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
int n, m, dfn[N], low[N], timestamp, stk[N], top, id[N], scc_cnt, sz[N], dout[N];
bool in_stk[N];
vector<vector<int>>eg(N);
void add(int a, int b) {eg[a].emplace_back(b);}
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (auto it : eg[u]) {
		if (!dfn[it]) {
			tarjan(it);
			low[u] = min(low[u], low[it]);
		} else if (in_stk[it])low[u] = min(low[u], low[it]);
		//由于具有横插边，且已经被减去的强连通分量不可作为更新节点，因此添加
		//in_stk[]来判断是否可以用该点更新
	}

	if (dfn[u] == low[u]) {
		++scc_cnt;
		int y;

		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sz[scc_cnt]++;
		} while (y != u);
	}
}
void solve(int T) {
	cin >> n >> m;

	while (m--) {
		int u, v; cin >> u >> v;

		add(u, v);
	}

	for (int x = 1; x <= n; x++) {
		if (!dfn[x]) {
			tarjan(x);
		}
	}

	for (int x = 1; x <= n; x++) {
		for (auto it : eg[x]) {
			int a = id[x], b = id[it];
			if (a != b)dout[a]++;
		}
	}

	int zero = 0, ans = 0;

	for (int x = 1; x <= scc_cnt; x++) {
		if (!dout[x]) {
			zero++;
			ans += sz[x];
			if (zero > 1) {ans = 0; break;}
		}
	}

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
