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
//#define int long long
#define yes "Yes\n"
#define no "No\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
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

void solve() {
	int n, m; cin >> n >> m;
	Dij d(n);

	int a[7]; a[1] = 1;
	for (int x = 2; x <= 6; x++)cin >> a[x];

	while (m--) {
		int u, v, t; cin >> u >> v >> t;

		d.eg[u].emplace_back(v, t);
		d.eg[v].emplace_back(u, t);
	}

	map<PII, int>dis;

	for (int x = 1; x <= 6; x++) {
		d.dij(a[x]);
		for (int y = x + 1; y <= 6; y++) {
			dis[ {x, y}] = d.dist[a[y]];
			dis[ {y, x}] = d.dist[a[y]];
		}
	}

	vector<int> vis(7, 0); int ans = INF;
	auto dfs = [&](auto && dfs, int u, int s)->void{
		int cnt = 0;

		for (int x = 2; x <= 6; x++) {
			if (!vis[x]) {
				vis[x] = 1;
				dfs(dfs, x, s + dis[ {u, x}]);
				vis[x] = 0;
			}
			else cnt++;
		}
		if (cnt == 5)ans = min(ans, s);
	};

	dfs(dfs, 1, 0);

	cout << ans << '\n';
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
