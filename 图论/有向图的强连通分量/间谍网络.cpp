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
using LL = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, P, cost[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt;
int e[N], ne[N], h[N], idx;
int d[N];
vector<int>s[N];
int mnid = INF;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void targan(int u) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u]; ~i; i = ne[i]) {
		int it = e[i];
		if (!dfn[it]) {
			targan(it);
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
			s[scc_cnt].emplace_back(y);
		} while (y != u);
	}
}
void dfs(int u) {
	bool ok = false;
	int mn = INF;
	for (auto ver : s[u]) {
		if (cost[ver] >= 0)ok = true;
		else mn = min(mn, ver);
	}
	if (ok)return;
	else {
		mnid = min(mnid, mn);
		for (int i = h[u]; ~i; i = ne[i]) {
			int ver = e[i];
			dfs(ver);
		}
	}
}
void solve() {
	cin >> n >> P;
	vector<PII>p;
	memset(cost, -1, sizeof cost);
	memset(h, -1, sizeof h);
	for (int x = 1; x <= P; x++) {
		int i, c; cin >> i >> c;
		cost[i] = c;
	}
	int r; cin >> r;
	while (r--) {
		int u, v; cin >> u >> v;
		add(u, v);
		p.emplace_back(u, v);
	}
	for (int x = 1; x <= n; x++)
		if (!dfn[x])
			targan(x);
	memset(h, -1, sizeof h);
	idx = 0;
	set<PII>st;
	for (auto [u, v] : p) {
		int a = id[u], b = id[v];
		if (a != b) {
			d[b]++;
			st.insert({a, b});
		}
	}
	for (auto [u, v] : st)add(u, v);
	int sum = 0;
	bool Ok = true;
	for (int x = 1; x <= scc_cnt; x++) {
		if (!d[x]) {
			bool ok = false;
			int mn = INF;
			for (auto it : s[x]) {
				if (cost[it] >= 0) {
					mn = min(mn, cost[it]);
					ok = true;
				}
			}
			sum += mn;
			if (!ok)Ok = false;
		}
	}
	if (Ok)cout << "YES\n" << sum;
	else {
		for (int x = 1; x <= scc_cnt; x++)
			if (!d[x])
				dfs(x);
		cout << "NO\n" << mnid;
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int TT = 1;
	//cin >> T, cin.get();
	while (TT--) {
		solve();
	}
	return 0;
}
