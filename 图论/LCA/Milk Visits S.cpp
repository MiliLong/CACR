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
const int N = 2e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, p;
int fa[N][23], depth[N];
int e[2 * N], ne[2 * N], h[N], idx;
int d[N], q[N];
int son[N][2], sson[N][2];

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
				for (int k = 1; k <= 22; k++) {
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
				}
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);

	for (int k = 22; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b])a = fa[a][k];
	}

	if (a == b)return a;

	for (int k = 22; k >= 0; k--) {
		if (fa[a][k] != fa[b][k])a = fa[a][k], b = fa[b][k];
	}

	return fa[a][0];
}

void sdfs(int u, int f) {
	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == f)continue;

		sson[j][0] = sson[u][0] + son[j][0];
		sson[j][1] = sson[u][1] + son[j][1];
		sdfs(j, u);
	}
}

void solve() {
	cin >> n >> m;
	string s; cin >> s;
	for (int x = 1; x <= n; x++) {
		if (s[x - 1] == 'H')son[x][0] = 1;
		else son[x][1] = 1;
	}
	n--;

	while (n--) {
		int i, j; cin >> i >> j;

		add(i, j), add(j, i);
	}

	bfs();
	sdfs(1, 0);

	string as = "";

	while (m--) {
		int i, j; char c; cin >> i >> j >> c;
		int sf = lca(i, j);
		sf = fa[sf][0];

		int H = sson[i][0] + sson[j][0] - sson[sf][0] * 2;
		int G = sson[i][1] + sson[j][1] - sson[sf][1] * 2;

		if (c == 'H' && H >= 1)as += '1';
		else if (c == 'G' && G >= 1)as += '1';
		else as += '0';
	}

	cout << as << '\n';
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
