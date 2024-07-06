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

int n, p, k;

class Dij {
public:
	int n, _INF = 1e9;
	vector<vector<PII>>eg;
	vector<int>dist, vis;

	bool dij(int st, int m) {
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
				if (dist[it] > dist[vir] + (w > m)) {
					dist[it] = dist[vir] + (w > m);
					heap.push({dist[it], it});
				}
			}
		}

		return (dist[n] <= k);
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};

void solve() {
	cin >> n >> p >> k;

	Dij d(n);

	while (p--) {
		int u, v, w; cin >> u >> v >> w;

		d.eg[u].emplace_back(v, w);
		d.eg[v].emplace_back(u, w);
	}

	int l = 0, r = 1000000;

	while (l < r) {
		int md = (l + r) >> 1;

		if (d.dij(1, md))r = md;
		else l = md + 1;
	}

	if (d.dij(1, l))cout << l << '\n';
	else cout << -1 << '\n';

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
