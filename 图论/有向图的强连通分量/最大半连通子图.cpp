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
int n, m, mod;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, s[N];
int f[N], g[N];
vector<vector<int>>eg1(N), eg2(N);
unordered_set<int>mp;
void tarjan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (auto it : eg1[u]) {
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
	cin >> n >> m >> mod;

	while (m--) {
		int u, v; cin >> u >> v;
		eg1[u].emplace_back(v);
	}

	for (int x = 1; x <= n; x++)
		if (!dfn[x])
			tarjan(x);

	for (int x = 1; x <= n; x++) {
		for (auto it : eg1[x]) {
			int a = id[x], b = id[it];
			int hash = a * 1000000 + b;
			if ((a != b) && (!mp.count(hash))) {
				mp.insert(hash);
				eg2[a].emplace_back(b);
			}
		}
	}

	for (int x = scc_cnt; x >= 1; x--) {
		if (!f[x])f[x] = s[x], g[x] = 1;
		for (auto it : eg2[x]) {
			if (f[it] < f[x] + s[it]) {
				f[it] = f[x] + s[it];
				g[it] = g[x];
			} else if (f[it] == f[x] + s[it]) {
				g[it] += g[x];
				g[it] %= mod;
			}
		}
	}

	int maxf = 0, sum = 0;
	for (int x = 1; x <= scc_cnt; x++) {
		if (f[x] > maxf) {
			maxf = f[x];
			sum = g[x];
		} else if (f[x] == maxf) {
			sum += g[x];
			sum %= mod;
		}
	}
	cout << maxf << '\n' << sum << '\n';
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
