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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

class Dij {
public:
	int n, _INF = 1e18;
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

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<array<int, 3>>a;
	vector<int>ans, pos(n + 1, 0);
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		a.push_back({w, u, v});
	}
	sort(all(a));
	set<int>st;
	for (int x = 0; x < k && x < a.size(); x++) {
		auto [w, u, v] = a[x];
		st.insert(u);
		st.insert(v);
	}
	int ct = 0;
	for (auto it : st)pos[it] = ++ct;
	Dij d(ct);
	for (int x = 0; x < k && x < a.size(); x++) {
		auto [w, u, v] = a[x];
		d.eg[pos[u]].push_back({pos[v], w});
		d.eg[pos[v]].push_back({pos[u], w});
	}
	map<PII, bool>vis;
	for (auto it : st) {
		it = pos[it];
		d.dij(it);
		for (auto x : st) {
			x = pos[x];
			if (x == it)continue;
			if (!vis.count({min(x, it), max(x, it)}))ans.push_back(d.dist[x]);
			vis[ {min(x, it), max(x, it)}] = 1;
		}
	}
	sort(all(ans));
	cout << ans[k - 1] << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
