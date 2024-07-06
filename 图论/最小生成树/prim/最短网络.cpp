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

class Prim {
public:
	int n, _INF = 1e18;
	vector<vector<PII>>eg;
	vector<int>dist, vis;

	int prim(int st) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);

		int res = 0, cnt = 0;
		dist[st] = 0;
		priority_queue<PII, vector<PII>, greater<PII>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = true;
			cnt++;
			if (dis == _INF)return _INF;

			res += dis;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] > w) {
					dist[it] = w;
					heap.push({dist[it], it});
				}
			}
		}
		if (cnt == n)return res;
		else return _INF;
	}

	Prim(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};

void solve() {
	int n; cin >> n;
	Prim p(n);
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++) {
			int i; cin >> i;
			if (x == y)continue;
			p.eg[x].emplace_back(y, i);
		}

	cout << p.prim(1) << '\n';
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
