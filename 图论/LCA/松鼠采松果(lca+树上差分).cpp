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

int n, m, p;
int fa[N][17], depth[N];
int e[2 * N], ne[2 * N], h[N], idx;
int d[N], q[N];
int son[N], sson[N];

void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs() {
	memset(depth, INF, sizeof depth);
	depth[0] = 0, depth[1] = 1;

	q[0] = 1;
	int hh = 0, tt = 0;
	while (hh <= tt) {
		int t = q[hh++];

		for (int i = h[t]; i; i = ne[i]) {
			int j = e[i];

			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				q[++tt] = j;

				fa[j][0] = t;
				for (int k = 1; k <= 16; k++) {
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
				}
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);

	for (int k = 16; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b])a = fa[a][k];
	}

	if (a == b)return a;

	for (int k = 16; k >= 0; k--) {
		if (fa[a][k] != fa[b][k])a = fa[a][k], b = fa[b][k];
	}

	return fa[a][0];
}

int dfs(int u, int f) {
	int res = d[u];

	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == f)continue;

		res += dfs(j, u);
	}

	return son[u] = res;
}

void sdfs(int u, int f) {
	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == f)continue;

		sson[j] = sson[u] + son[j];
		sdfs(j, u);
	}
}

void solve() {
	cin >> n >> m >> p;

	vector<tuple<int, int, int>>eg(n - 1);

	for (auto &[i, j, w] : eg) {
		cin >> i >> j >> w;

		add(i, j), add(j, i);
	}

	bfs();

	for (auto [i, j, w] : eg) {
		int sf = lca(i, j);

		d[i] += w, d[j] += w, d[sf] -= 2 * w;
	}

	while (m--) {
		int i, j, w; cin >> i >> j >> w;
		int sf = lca(i, j);

		d[i] += w, d[j] += w, d[sf] -= 2 * w;
	}

	dfs(1, 0);
	sdfs(1, 0);

	while (p--) {
		int i, j; cin >> i >> j;
		int sf = lca(i, j);

		cout << sson[i] + sson[j] - sson[sf] * 2 << '\n';
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
