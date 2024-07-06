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
#define yes "Yes\n"
#define no "No\n";
using ll = long long;
const int N = 1e6 + 10, INF = 1e18;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

class Dij {
public:
	int n, _INF = 1e18;
	vector<vector<PII>>eg;
	vector<int>dist, vis, rank;

	int dij(int st, int l, int r) {
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
				if (rank[it] < l || rank[it] > r)continue;
				if (dist[it] > dist[vir] + w) {
					dist[it] = dist[vir] + w;
					heap.push({dist[it], it});
				}
			}
		}

		return dist[1];
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1), rank(in + 1) {};

};

void solve() {
	int m, n; cin >> m >> n;

	Dij d(n);

	for (int x = 1; x <= n; x++) {
		int p, l, c; cin >> p >> l >> c;
		d.rank[x] = l; d.eg[0].emplace_back(x, p);
		for (int y = 1; y <= c; y++) {
			int t, cos; cin >> t >> cos;

			d.eg[t].emplace_back(x, cos);
		}
	}

	int ans = INF;

	for (int i = d.rank[1] - m; i <= d.rank[1]; i++) {

		ans = min(ans, d.dij(0, i, i + m));
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
