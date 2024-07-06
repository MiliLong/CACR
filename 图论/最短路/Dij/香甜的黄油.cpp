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
	int c, n, m; cin >> c >> n >> m ;
	vector<vector<PII>>eg(n + 1);
	vector<int>dist(n + 1, N), vis(n + 1, 0), cow(c);

	for (int x = 0; x < c; x++)cin >> cow[x];
	while (m--) {
		int i, j, w; cin >> i >> j >> w;

		eg[i].emplace_back(j, w);
		eg[j].emplace_back(i, w);
	}

	auto dij = [&](int st) {
		dist.insert(dist.begin(), n + 1, N);
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

	};

	int ans = N;

	for (int x = 1; x <= n; x++) {
		dij(x);

		int md = 0;
		for (auto it : cow) {
			md += dist[it];
		}
		ans = min(ans, md);
	}

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
