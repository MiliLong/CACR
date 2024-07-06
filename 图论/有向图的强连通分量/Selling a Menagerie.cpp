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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int a[N], c[N], as[N];
int mn, name, all;
vector<vector<int>>eg;
void init() {
	eg.clear();
	eg.resize(n + 1);
	for (int x = 0; x <= n; x++) {
		dfn[x] = stk[x] = sz[x] = id[x] = in_stk[x] = 0;
	}
	timestamp = top = scc_cnt = 0;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (auto it : eg[u]) {
		if (!dfn[it]) {
			tarjan(it);
			low[u] = min(low[u], low[it]);
		} else if (in_stk[it])low[u] = min(low[u], low[it]);
	}

	if (dfn[u] == low[u]) {
		++scc_cnt;
		as[scc_cnt] = u;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sz[scc_cnt]++;
		} while (y != u);
	}
}
void dfs(int u) {
	if (c[u] <= mn) {
		mn = c[u]; name = u;
	}
	all--;
	if (all)dfs(eg[u][0]);
}
void cdfs(int u) {
	cout << u << ' ';
	all--;
	if (all)cdfs(eg[u][0]);
}
void solve(int T) {
	cin >> n;
	init();
	for (int x = 1; x <= n; x++) {
		int y; cin >> y;
		a[x] = y;
		eg[x].emplace_back(y);
	}
	for (int x = 1; x <= n; x++)cin >> c[x];

	for (int x = 1; x <= n; x++) {
		if (!dfn[x])
			tarjan(x);
	}

	for (int x = scc_cnt; x >= 1; x--) {
		if (sz[x] == 1) {
			cout << as[x] << ' ';
			continue;
		}
		mn = INF, name = 0, all = sz[x];
		dfs(as[x]);
		all = sz[x];
		cdfs(a[name]);
	}
	cout << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
