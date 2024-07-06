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
int root, ans;
vector<vector<int>>eg;
void init() {
	for (int x = 0; x <= n; x++) {
		dfn[x] = low[x] = 0;
	}
	ans = timestamp = 0;
	eg.clear();
	eg.resize(n + 1);
}
void add(int a, int b) {eg[a].emplace_back(b);}
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	int cnt = 0;//除去父父块外额外可割去的块
	for (auto it : eg[u]) {
		if (!dfn[it]) {
			tarjan(it);
			low[u] = min(low[u], low[it]);
			if (low[it] >= dfn[u])cnt++;//子块与父父块除去经过父节点外不通，接下来统计以父节点为割点的子块数
		} else low[u] = min(low[u], dfn[it]);
	}

	if (u != root)cnt++;//非树根有父节点块即统计上父父块(根节点无父父块)
	ans = max(ans, cnt);
}
void solve(int T) {
	while (cin >> n >> m, n || m) {
		init();
		while (m--) {
			int u, v; cin >> u >> v;
			u++, v++;
			add(u, v), add(v, u);
		}
		int cnt = 0;

		for (root = 1; root <= n; root++) {
			if (!dfn[root]) {
				cnt++;//连通块++
				tarjan(root);
			}
		}

		cout << ans + cnt - 1 << '\n';//目标块的最大分块数+连通块数-目标块(1)
	}
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
