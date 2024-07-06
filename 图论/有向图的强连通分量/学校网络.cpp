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
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, dfn[N], low[N], in_stk[N], stk[N], scc_cnt, top, id[N], din[N], dout[N], timestamp;
vector<vector<int>>eg(N);
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
		} while (y != u);
	}
}
void solve(int T) {
	cin >> n;
	for (int x = 1; x <= n; x++) {
		int y;
		while (cin >> y) {
			if (!y)break;
			eg[x].emplace_back(y);
		}
	}

	for (int x = 1; x <= n; x++) {
		if (!dfn[x]) {
			tarjan(x);
		}
	}

	for (int x = 1; x <= n; x++)
		for (auto it : eg[x]) {
			int a = id[x], b = id[it];
			if (a != b) {
				dout[a]++;
				din[b]++;
			}
		}

	int ans_st = 0, ans_ed = 0;

	for (int x = 1; x <= scc_cnt; x++) {
		if (!din[x])ans_st++;
		if (!dout[x])ans_ed++;
	}
	cout << ans_st << '\n';
	if (scc_cnt == 1)cout << 0 << '\n';
	else cout << max(ans_st, ans_ed) << '\n';
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
