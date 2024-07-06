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
using ll = long long;
const int N = 1e8 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

class Dij {
public:
	int n;
	vector<vector<int>>eg;
	vector<int>dist, vis;

	void dij(int st) {
		dist.insert(dist.begin(), n + 1, N);
		vis.insert(vis.begin(), n + 1, 0);
		dist[st] = 0;
		priority_queue<PII, vector<PII>, greater<PII>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = 1;

			for (auto it : eg[vir]) {
				if (dist[it] > dist[vir] + 1) {
					dist[it] = dist[vir] + 1;
					heap.push({dist[it], it});
				}
			}
		}
	}

	Dij(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};

void solve() {
	int m, n; cin >> m >> n;

	Dij d(n);

	while (m--) {
		vector<int>a;
		char c;
		int i;
		while (cin >> i) {
			c = cin.get();
			a.emplace_back(i);
			if (c == '\n')break;
		}
		for (int x = 0; x < a.size(); x++) {
			for (int y = x + 1; y < a.size(); y++) {
				d.eg[a[x]].emplace_back(a[y]);
			}
		}
	}

	d.dij(1);

	if (d.dist[n] == N)cout << "NO\n";
	else if (1 == n)cout << 0 << '\n';
	else cout << d.dist[n] - 1 << '\n';
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
