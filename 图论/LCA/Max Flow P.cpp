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
int n, m, ans = 0;
vector<vector<int>>eg;
int depth[N], fa[N][32], res[N];
void dfs(int u, int f) {
	for (auto it : eg[u]) {
		if (it == f)continue;
		if (depth[it] > depth[u] + 1) {
			depth[it] = depth[u] + 1;
			fa[it][0] = u;
			for (int k = 1; k < 32; k++) {
				fa[it][k] = fa[fa[it][k - 1]][k - 1];
			}
			dfs(it, u);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);
	for (int k = 31; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}
	if (a == b)return a;
	for (int k = 31; k >= 0; k--) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}

void Dfs(int u, int f) {
	for (auto it : eg[u]) {
		if (it == f)continue;
		Dfs(it, u);
		res[u] += res[it];
	}
	ans = max(ans, res[u]);
}
void solve(int T) {
	cin >> n >> m;
	eg.resize(n + 1);
	for (int x = 0; x < n - 1; x++) {
		int u, v; cin >> u >> v;
		eg[u].emplace_back(v);
		eg[v].emplace_back(u);
	}
	for (int x = 2; x <= n; x++)depth[x] = INF;
	depth[1] = 1;
	dfs(1, 0);

	while (m--) {
		int u, v; cin >> u >> v;
		int r = lca(u, v);
		res[u]++, res[v]++, res[r]--, res[fa[r][0]] --;
	}

	Dfs(1, 0);

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
