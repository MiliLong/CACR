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
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m;
char g[3010][3010];
int h[3010][3010], dist[3010][3010];
void bfs() {
	deque<PII>q;
	q.emplace_back(1, 1);
	dist[1][1] = 0;
	while (q.size()) {
		auto [x, y] = q.front(); q.pop_front();

		if (x == n && y == m) {
			cout << dist[x][y] << '\n';
			return;
		}

		if (h[x][y]) {
			for (int i = 0; i < 4; i++) {
				int na = x + dx[i] * h[x][y], nb = y + dy[i] * h[x][y];
				if (na > n || na < 1 || nb > m || nb < 1)continue;
				if (g[na][nb] == '#')continue;
				if (dist[na][nb] > dist[x][y]) {
					dist[na][nb] = dist[x][y];
					q.emplace_front(na, nb);
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int na = x + dx[i], nb = y + dy[i];
				if (na > n || na < 1 || nb > m || nb < 1)continue;
				if (g[na][nb] == '#')continue;
				if (dist[na][nb] > dist[x][y] + 1) {
					dist[na][nb] = dist[x][y] + 1;
					q.emplace_back(na, nb);
				}
			}
		}
	}
	cout << -1 << '\n';
}
void solve() {
	memset(dist, INF, sizeof dist);
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> g[x] + 1;
	int k; cin >> k;
	while (k--) {
		int i, j, w; cin >> i >> j >> w;
		if (w > max(n, m))continue;
		h[i][j] = w;
	}
	bfs();
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
