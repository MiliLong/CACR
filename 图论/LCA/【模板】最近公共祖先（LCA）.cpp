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
const int N = 3e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, q;
int fa[N][23], depth[N];
int e[2 * N], ne[2 * N], h[N], idx;
int p[N];

void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs(int root) {
	memset(depth, INF, sizeof depth);
	depth[0] = 0, depth[root] = 1;

	p[0] = root;
	int hh = 0, tt = 0;
	while (hh <= tt) {
		int t = p[hh++];

		for (int i = h[t]; i; i = ne[i]) {
			int j = e[i];

			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				p[++tt] = j;

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

void solve() {
	cin >> n >> m >> q;
	n--;

	while (n--) {
		int i, j; cin >> i >> j;

		add(i, j), add(j, i);
	}

	bfs(q);

	while (m--) {
		int i, j; cin >> i >> j;

		cout << lca(i, j) << '\n';
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
