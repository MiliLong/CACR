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
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, s[N];
int d[N];
vector<vector<int>>eg;
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
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			s[scc_cnt]++;
		} while (y != u);
	}
}
void solve(int T) {
	cin >> n >> m;
	eg.resize(n + 1);
	while (m--) {
		int u, v; cin >> u >> v;
		eg[u].emplace_back(v);
	}
	for (int x = 1; x <= n; x++) {
		if (!dfn[x])
			tarjan(x);
	}

	for (int x = 1; x <= n; x++)
		for (auto it : eg[x]) {
			int a = id[x], b = id[it];
			if (a != b)d[a]++;
		}
	int res = 0, cnt = 0;
	for (int x = 1; x <= scc_cnt; x++) {
		if (!d[x]) {
			cnt++;
			res = s[x];
		}
	}
	if (cnt == 1)cout << res << '\n';
	else cout << 0 << '\n';
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
