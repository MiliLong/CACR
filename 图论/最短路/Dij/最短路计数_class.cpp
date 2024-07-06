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

int mod = 100003;
class Dij {
public:
	int n, _INF = 1e9;
	vector<vector<int>>eg;
	vector<int>dist, vis, cnt;

	void dij(int st) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);
		cnt.insert(cnt.begin(), n + 1, 0);

		dist[st] = 0; cnt[st] = 1;
		priority_queue<PII, vector<PII>, greater<PII>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = 1;

			for (auto it : eg[vir]) {
				if (dist[it] > dist[vir] + 1) {
					cnt[it] = cnt[vir];

					dist[it] = dist[vir] + 1;
					heap.push({dist[it], it});
				}
				else if (dist[it] == dist[vir] + 1) {cnt[it] += cnt[vir]; cnt[it] %= mod;}
			}
		}
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1), cnt(in + 1) {};

};

void solve() {
	int n, m; cin >> n >> m;

	Dij d(n);
	while (m--) {
		int u, v; cin >> u >> v;

		d.eg[u].emplace_back(v);
		d.eg[v].emplace_back(u);
	}

	d.dij(1);
	for (int x = 1; x <= n; x++)cout << d.cnt[x] << '\n';
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
