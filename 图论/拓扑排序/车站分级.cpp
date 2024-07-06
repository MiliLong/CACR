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
int n, m;
int din[N], dist[N];
vector<vector<PII>>eg(N);
vector<int>tp;
void add(int a, int b, int c) {
	eg[a].emplace_back(b, c);
	din[b]++;
}
void topsort() {
	queue<int>que;
	for (int x = 1; x <= n + m; x++)
		if (!din[x])que.push(x);
	while (que.size()) {
		int t = que.front(); que.pop();
		tp.emplace_back(t);
		for (auto [it, w] : eg[t]) {
			if (!(--din[it]))
				que.push(it);
		}
	}
}
void solve(int T) {
	cin >> n >> m;
	for (int x = 1; x <= m; x++) {
		vector<bool>in(n + 1, false);
		int cnt; cin >> cnt;
		int st = n, ed = 1;
		while (cnt--) {
			int i; cin >> i;
			st = min(st, i);
			ed = max(ed, i);
			in[i] = true;
		}
		int v = n + x;//虚拟节点
		for (int x = st; x <= ed; x++) {
			if (!in[x])add(x, v, 0);
			else add(v, x, 1);
		}
	}
	topsort();
	for (int x = 1; x <= n; x++)dist[x] = 1;
	for (int x = 0; x < n + m; x++) {
		int u = tp[x];
		for (auto [it, w] : eg[u]) {
			dist[it] = max(dist[it], dist[u] + w);
		}
	}
	int res = 0;
	for (int x = 1; x <= n; x++)res = max(res, dist[x]);
	cout << res << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
