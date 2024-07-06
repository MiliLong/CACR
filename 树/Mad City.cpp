#include<bits/stdc++.h>
//#pragma GCC optimize (1)
//#pragma GCC optimize (2)
//#pragma GCC optimize (3)
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long
#define yes "YES\n"
#define no "NO\n";
using LL = long long;
const int N = 1e6 + 10, INF = 1e17;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
class Dij {
public:
	int n, _INF = 1e9;
	vector<vector<PII>>eg;
	vector<int>dist, vis;

	void dij(int st) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);
		dist[st] = 0;
		priority_queue<PII, vector<PII>, greater<PII>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = 1;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] > dist[vir] + w) {
					dist[it] = dist[vir] + w;
					heap.push({dist[it], it});
				}
			}
		}
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};
int n, a, b;
int e[N], ne[N], idx, h[N], t[N], T, ok[N], r;
void add(int u, int v) {
	e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}
void dfs(int u, int fa) {
	if (t[u] < t[fa] && t[u]) {
		r = u;
		ok[fa] = true;
		return;
	}
	t[u] = ++T;
	for (int i = h[u]; ~i; i = ne[i]) {
		int ver = e[i];
		if (ver == fa)continue;
		dfs(ver, u);
	}
	if (ok[u] && t[fa] >= t[r])ok[fa] = true;
}
void solve() {
	cin >> n >> a >> b;
	Dij d(n);
	for (int x = 1; x <= n; x++) {
		t[x] = ok[x] = T = r = 0;
		int u, v; cin >> u >> v;
		d.eg[u].emplace_back(v, 1);
		d.eg[v].emplace_back(u, 1);
		add(u, v);
		add(v, u);
	}
	d.dij(a);
	vector<int>da, db;
	da = d.dist;
	d.dij(b);
	db = d.dist;
	dfs(b, 0);
	int mn = INF, p = -1;
	for (int x = 1; x <= n; x++)
		if (ok[x]) {
			if (db[x] < mn) {
				mn = db[x];
				p = x;
			}
		}
	if (db[p] < da[p])cout << yes;
	else cout << no;
	for (int x = 0; x < idx; x++)h[x] = -1;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int TT = 1;
	cin >> TT, cin.get();
	memset(h, -1, sizeof h);
	while (TT--) {
		solve();
	}
	return 0;
}
