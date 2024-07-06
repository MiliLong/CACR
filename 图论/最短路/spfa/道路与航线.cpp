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

class Spfa {
public:
	int n, _INF = 1e18;
	vector<vector<PII>>eg;
	vector<int>dist, vis;

	void spfa(int st) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);

		dist[st] = 0; vis[st] = 1;
		deque<int>heap;

		heap.push_front(st);
		while (heap.size()) {
			auto vir = heap.front(); heap.pop_front();
			vis[vir] = 0;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] > dist[vir] + w) {
					dist[it] = dist[vir] + w;

					if (vis[it])continue;
					vis[it] = 1;

					if (!heap.empty() && dist[it] < dist[heap.front()])heap.push_front(it);
					else heap.push_back(it);
				}
			}
		}
	}

	Spfa(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};

void solve() {
	int t, r, p, s; cin >> t >> r >> p >> s;

	Spfa sp(t);

	while (r--) {
		int u, v, w; cin >> u >> v >> w;

		sp.eg[u].emplace_back(v, w);
		sp.eg[v].emplace_back(u, w);
	}

	while (p--) {
		int u, v, w; cin >> u >> v >> w;

		sp.eg[u].emplace_back(v, w);
	}

	sp.spfa(s);

	for (int x = 1; x <= t; x++) {
		if (sp.dist[x] == 1e18)cout << "NO PATH\n";
		else cout << sp.dist[x] << '\n';
	}

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
