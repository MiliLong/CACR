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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
struct node {
	int dist, id, typle;

	bool operator <(const node&W)const {
		return dist > W.dist;
	}
	/*	bool operator >(const node&W)const {
			return dist > W.dist;
		}*/
};
class Dij {
public:
	int n, _INF = 1e9;
	vector<vector<PII>>eg;
	vector<vector<int>>dist, vis, cnt;

	void dij(int st) {
		dist[st][0] = 0; cnt[st][0] = 1;
		priority_queue<node/*, vector<node>, greater<node>*/>heap;

		heap.push({dist[st][0], st, 0});
		while (heap.size()) {
			auto [dis, vir, tp] = heap.top(); heap.pop();

			if (vis[vir][tp])continue;
			vis[vir][tp] = 1;

			for (auto [it, w] : eg[vir]) {
				if (dist[it][0] > dis + w) {

					dist[it][1] = dist[it][0];
					cnt[it][1] = cnt[it][0];

					heap.push({dist[it][1], it, 1});

					dist[it][0] = dis + w;
					cnt[it][0] = cnt[vir][tp];

					heap.push({dist[it][0], it, 0});
				}
				else if (dist[it][0] == dis + w) {cnt[it][0] += cnt[vir][tp];}
				else if (dist[it][1] > dis + w) {

					dist[it][1] = dis + w;
					cnt[it][1] = cnt[vir][tp];

					heap.push({dist[it][1], it, 1});
				}
				else if (dist[it][1] == dis + w) {cnt[it][1] += cnt[vir][tp];}
			}
		}
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1, vector<int>(2, _INF)), vis(in + 1, vector<int>(2, 0)), cnt(in + 1, vector<int>(2, 0)) {};

};

void solve() {
	int n, m; cin >> n >> m;

	Dij d(n);

	while (m--) {
		int u, v, w; cin >> u >> v >> w;

		d.eg[u].emplace_back(v, w);
	}

	int s, f; cin >> s >> f;

	d.dij(s);

	int ans = d.cnt[f][0];
	if (d.dist[f][1] - 1 == d.dist[f][0])ans += d.cnt[f][1];

	cout << ans << '\n';

}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
