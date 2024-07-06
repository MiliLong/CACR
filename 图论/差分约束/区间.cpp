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
	int n;
	vector<vector<PII>>eg;
	vector<int>vis, dist;

	void spfa(int st) {
		dist.insert(dist.begin(), n + 1, -INF);
		vis.insert(vis.begin(), n + 1, 0);

		queue<int>que;
		que.push(st);
		vis[st] = 1; dist[st] = 0;

		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = 0;

			for (auto [it, w] : eg[t]) {
				if (dist[it] < dist[t] + w) {
					dist[it] = dist[t] + w;
					if (!vis[it]) {
						vis[it] = 1; que.push(it);
					}
				}
			}
		}
	}

	void add(int a, int b, int c) {
		eg[a].push_back({b, c});
	}

	SPFA(int n): n(n), dist(n + 1), vis(n + 1), eg(n + 1) {};
};
void solve(int T) {
	int n; cin >> n;
	SPFA s(50001);

	for (int x = 1; x <= 50001; x++) {
		s.add(x - 1, x, 0);
		s.add(x, x - 1, -1);
	}

	for (int x = 0; x < n; x++) {
		int a, b, c; cin >> a >> b >> c;
		a++, b++;
		s.add(a - 1, b, c);
	}

	s.spfa(0);

	cout << s.dist[50001];
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
