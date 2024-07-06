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
const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int f[N];

class SPFA {
public:
	int n;
	vector<vector<array<int, 3>>>eg;
	vector<int> vis, cnt;
	vector<double>dist;

	bool spfa(double u) {
		dist.insert(dist.begin(), n + 1, 0.0);
		vis.insert(vis.begin(), n + 1, 0);
		cnt.insert(cnt.begin(), n + 1, 0);
		queue<int>que;
		for (int x = 1; x <= n; x++) {
			que.push(x);
			vis[x] = true;
		}

		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = false;

			for (auto [it, w, v] : eg[t]) {
				if (dist[it] < dist[t] + 1.0 * v - 1.0 * u * w) {
					dist[it] = dist[t] + 1.0 * v - 1.0 * u * w;
					cnt[it] = cnt[t] + 1;
					if (cnt[it] >= n)return true;
					if (!vis[it]) {
						vis[it] = true;
						que.push(it);
					}
				}
			}
		}
		return false;
	}

	SPFA(int in): n(in), dist(in + 1), vis(in + 1), cnt(in + 1), eg(n + 1) {};
};
void solve() {
	int l, p; cin >> l >> p;
	for (int x = 1; x <= l; x++)cin >> f[x];

	SPFA s(l);
	for (int x = 1; x <= p; x++) {
		int u, v, w; cin >> u >> v >> w;
		s.eg[u].push_back({v, w, f[u]});
	}

	double ll = 0, rr = 1010;
	while (rr - ll > 1e-5) {
		double mid = (ll + rr) / 2;
		if (s.spfa(mid))ll = mid;
		else rr = mid;
	}

	cout << fixed << setprecision(2) << ll << '\n';
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
