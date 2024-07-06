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
const int N = 2e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
vector<vector<PII>>eg1, eg2;
int dist[N];
void add(vector<vector<PII>>&eg, int u, int v, int w) {
	eg[u].emplace_back(v, w);
}
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (auto [it, w] : eg1[u]) {
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
			sz[scc_cnt]++;
		} while (y != u);
	}
}
void solve(int T) {
	cin >> n >> m;
	eg1.resize(n + 1);
	for (int x = 1; x <= n; x++)add(eg1, 0, x, 1);
	while (m--) {
		int u, v, t; cin >> t >> u >> v;
		if (t == 1) add(eg1, u, v, 0), add(eg1, v, u, 0);
		else if (t == 2)add(eg1, u, v, 1);
		else if (t == 3)add(eg1, v, u, 0);
		else if (t == 4)add(eg1, v, u, 1);
		else add(eg1, u, v, 0);
	}

	tarjan(0);
	eg2.resize(scc_cnt + 1);

	bool ok = true;
	for (int x = 0; x <= n; x++) {
		for (auto [it, w] : eg1[x]) {
			int a = id[x], b = id[it];
			if (a == b && w > 0) {
				ok = false;
				break;
			}
			else if (a != b)add(eg2, a, b, w);
		}
		if (!ok)break;
	}

	if (!ok)cout << -1 << '\n';
	else {
		for (int x = scc_cnt; x >= 1; x--) {
			for (auto [it, w] : eg2[x]) {
				dist[it] = max(dist[it], dist[x] + w);
			}
		}
		int res = 0;
		for (int x = 1; x <= scc_cnt; x++)res += dist[x] * sz[x];
		cout << res << '\n';
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
