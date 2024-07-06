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
int n, m, ans = 0, d[N], depth[N], fa[N][17];
vector<vector<int>>eg(N);
void add(int a, int b) {eg[a].emplace_back(b);}
void bfs() {
	memset(depth, 0x3f, sizeof depth);

	depth[0] = 0; depth[1] = 1;
	queue<int>que;
	que.push(1);

	while (que.size()) {
		int t = que.front(); que.pop();
		for (auto it : eg[t]) {
			if (depth[it] > depth[t] + 1) {
				depth[it] = depth[t] + 1;
				que.push(it);

				fa[it][0] = t;
				for (int k = 1; k <= 16; k++) {
					fa[it][k] = fa[fa[it][k - 1]][k - 1];
				}
			}
		}
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);

	for (int k = 16; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b]) {a = fa[a][k];}
	}

	if (a == b)return a;

	for (int k = 16; k >= 0; k--) {
		if (fa[a][k] != fa[b][k]) {//不是depth,而是点
			a = fa[a][k]; b = fa[b][k];
		}
	}

	return fa[a][0];
}

int dfs(int u, int f) {
	int res = d[u];
	for (auto it : eg[u]) {
		if (it == f)continue;

		int s = dfs(it, u);
		if (s == 0)ans += m;
		else if (s == 1)ans++;
		res += s;
	}

	return res;
}
void solve(int T) {
	cin >> n >> m;
	for (int x = 0; x < n - 1; x++) {
		int u, v; cin >> u >> v;
		add(u, v);
		add(v, u);
	}

	bfs();

	for (int x = 0; x < m; x++) {
		int u, v; cin >> u >> v;
		d[u]++, d[v]++, d[lca(u, v)] -= 2;
	}
	dfs(1, 0);
	cout << ans << '\n';
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
