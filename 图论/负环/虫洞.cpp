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
class SPFA {
public:
	int n, _INF = 1e18;
	vector<vector<PII>>eg;
	vector<int>dist, vis, cnt;

	bool spfa() {
		dist.insert(dist.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, false);
		cnt.insert(cnt.begin(), n + 1, 0);
		queue<int>que;
		for (int x = 1; x <= n; x++) {
			que.push(x);
			vis[x] = true;
		}

		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = false;
			for (auto [it, w] : eg[t]) {
				if (dist[it] > dist[t] + w) {
					dist[it] = dist[t] + w;
					cnt[it] = cnt[t] + 1;
					if (cnt[it] >= n)return true;
					if (!vis[it]) {que.push(it); vis[it] = true;}
				}
			}
		}

		return false;

	};

	SPFA(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1), cnt(in + 1) {};
};
void solve() {
	int n, m, w; cin >> n >> m >> w;
	SPFA s(n);

	for (int x = 0; x < m; x++) {
		int u, v, t; cin >> u >> v >> t;
		s.eg[u].emplace_back(v, t);
		s.eg[v].emplace_back(u, t);
	}
	for (int x = 0; x < w; x++) {
		int u, v, t; cin >> u >> v >> t;
		s.eg[u].emplace_back(v, -1 * t);
	}
	if (s.spfa()) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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
