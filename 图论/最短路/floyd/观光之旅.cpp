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
const int N = 1e2 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, g[N][N], d[N][N], cnt, path[N], pos[N][N], res = INF;
void get_path(int i, int j) {
	if (pos[i][j] == 0)return;

	int k = pos[i][j];
	get_path(i, k);
	path[cnt++] = k;
	get_path(k, j);
}

void solve() {
	cin >> n >> m;

	memset(g, 2, sizeof g);
	for (int x = 1; x <= n; x++)g[x][x] = 0;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;

		g[u][v] = g[v][u] = min(g[u][v], w);
	}

	copy(&g[0][0], &g[0][0] + N * N, &d[0][0]);
	//memcpy(d, g, sizeof d);

	for (int k = 1; k <= n; k++) {
		for (int x = 1; x < k; x++)
			for (int y = x + 1; y < k; y++)
				if (d[x][y] + g[y][k] + g[k][x] < res) {
					res = d[x][y] + g[y][k] + g[k][x];
					cnt = 0;
					path[cnt++] = k;
					path[cnt++] = x;
					get_path(x, y);
					path[cnt++] = y;
				}

		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= n; y++)
				if (d[x][y] > d[x][k] + d[k][y]) {
					d[x][y] = d[x][k] + d[k][y];
					pos[x][y] = k;
				}
	}

	if (res >= INF)cout << "No solution.\n";
	else {
		for (int x = 0; x < cnt; x++)cout << path[x] << ' ';
		cout << '\n';
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
