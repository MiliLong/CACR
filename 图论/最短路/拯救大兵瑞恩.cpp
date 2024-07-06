#include<bits/stdc++.h>
//#pragma GCC optimize (1)
#pragma GCC optimize (2)
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

int n, m, p;
int g[11][11], key[111];
set<PII>isset;

void build() {

	int cnt = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			g[x][y] = ++cnt;
		}
	}

}
class Bfs {
public:
	int _n, _INF = 1e9;
	vector<vector<PII>>eg;
	vector<vector<int>>dist, vis;

	int bfs() {
		dist[1][0] = 0;
		deque<PII>que;

		que.push_front({1, 0});
		while (que.size()) {
			auto [vir, state] = que.front(); que.pop_front();

			if (vir == _n)return dist[vir][state];

			if (vis[vir][state])continue;
			vis[vir][state] = true;

			if (key[vir]) {
				int _state = state | key[vir];

				if (dist[vir][_state] > dist[vir][state]) {

					dist[vir][_state] = dist[vir][state];
					que.push_front({vir, _state});
				}
			}

			for (auto [it, door] : eg[vir]) {

				if (door && !((state >> (door - 1)) & 1)) continue;
				if (dist[it][state] > dist[vir][state] + 1) {
					dist[it][state] = dist[vir][state] + 1;
					que.push_back({it, state});
				}
			}

		}

		return -1;
	}

	Bfs(int in): _n(in), eg(in + 1), dist(in + 1, vector<int>(1 << 10, _INF)), vis(in + 1, vector<int>(1 << 10, 0)) {};

};

void init(Bfs &b) {

	for (int x = 1; x <= n; x++) {

		for (int y = 1; y <= m; y++) {

			for (int z = 0; z < 4; z++) {

				int nx = x + dx[z], ny = y + dy[z];
				if (!nx || nx > n || !ny || ny > m)continue;

				int u = g[x][y], v = g[nx][ny];
				if (isset.count({u, v}) == 0)b.eg[u].emplace_back(v, 0);
			}
		}
	}
}

void solve() {
	cin >> n >> m >> p;

	build();
	Bfs  b(n * m);

	int k; cin >> k;

	while (k--) {
		int x1, y1, x2, y2, c; cin >> x1 >> y1 >> x2 >> y2 >> c;

		int x = g[x1][y1], y = g[x2][y2];

		isset.insert({x, y}); isset.insert({y, x});
		if (c) {b.eg[x].emplace_back(y, c); b.eg[y].emplace_back(x, c);}
	}

	init(b);

	int s; cin >> s;

	while (s--) {
		int x, y, c; cin >> x >> y >> c;

		key[g[x][y]] |= 1 << (c - 1);
	}

	cout << b.bfs() << '\n';

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
