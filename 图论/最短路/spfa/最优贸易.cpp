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

class Spfa {
public:
	int n, _INF = 1e9;
	vector<vector<int>>eg;
	vector<int>dist, vis, cost;

	void spfa(int st, bool mn) {
		if (mn)dist.insert(dist.begin(), n + 1, _INF);
		else dist.insert(dist.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, 0);

		dist[st] = cost[st], vis[st] = 1;
		deque<int>heap;

		heap.push_front(st);
		while (heap.size()) {
			auto vir = heap.front(); heap.pop_front();
			vis[vir] = 0;

			for (auto it : eg[vir]) {
				if (mn && dist[it] > min(dist[vir], cost[it])) {
					dist[it] =  min(dist[vir], cost[it]);

					if (vis[it])continue;
					vis[it] = 1;

					if (!heap.empty() && dist[it] < dist[heap.front()])heap.push_front(it);
					else heap.push_back(it);
				}
				else if ((!mn) && dist[it] < max(dist[vir], cost[it])) {
					dist[it] = max(dist[vir], cost[it]);

					if (vis[it])continue;
					vis[it] = 1;

					if (!heap.empty() && dist[it] > dist[heap.front()])heap.push_front(it);
					else heap.push_back(it);
				}
			}
		}
	}

	Spfa(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1), cost(in + 1) {};

};

void solve() {
	int n, m; cin >> n >> m;

	Spfa q(n), h(n);

	for (int x = 1; x <= n; x++) {
		cin >> q.cost[x];
		h.cost[x] = q.cost[x];
	}

	while (m--) {
		int x, y, z; cin >> x >> y >> z;

		q.eg[x].emplace_back(y); h.eg[y].emplace_back(x);
		if (z == 2) {q.eg[y].emplace_back(x); h.eg[x].emplace_back(y);}
	}

	vector<int>mn(n), ma(n);

	q.spfa(1, true);
	mn = q.dist;

	h.spfa(n, false);
	ma = h.dist;

	int ans = 0;

	for (int x = 1; x <= n; x++) {
		ans = max(ans, ma[x] - mn[x]);
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
