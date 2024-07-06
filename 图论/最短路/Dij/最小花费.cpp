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
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e8 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int  n, m; cin >> n >> m ;
	vector<vector<pair<int, double>>>eg(n + 1);
	vector<double>dist(n + 1); vector<int> vis(n + 1);

	while (m--) {
		int i, j; double w; cin >> i >> j >> w;

		eg[i].emplace_back(j, w);
		eg[j].emplace_back(i, w);
	}

	auto dij = [&](int st) {
		dist.insert(dist.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, 0);
		dist[st] = 1.0;
		priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = 1;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] < dist[vir] * (1.0 - w / 100.0)) {
					dist[it] = dist[vir] * (1.0 - w / 100.0);
					heap.push({dist[it], it});
				}
			}
		}

	};
	int a, b; cin >> a >> b;
	dij(a);

	cout << fixed << setprecision(8) << 100.0 / dist[b] << '\n';
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
