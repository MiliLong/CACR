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
const int N = 1e6 + 10, INF = 1e17;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, S, T;
int e[N], ne[N], f[N], h[N], idx;
int q[N], d[N], cur[N];
bool oks[N], okt[N];
vector<PII>p;
void add(int a, int b, int c) {
	e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
	e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}
bool bfs() {
	memset(d, -1, sizeof d);
	int hh = 0, tt = 0;
	q[0] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i]) {
			int ver = e[i];
			if (d[ver] == -1 && f[i]) {
				cur[ver] = h[ver];
				d[ver] = d[t] + 1;
				if (ver == T)return true;
				q[++tt] = ver;
			}
		}
	}
	return false;
}
int find(int u, int limit) {
	if (u == T)return limit;
	int flow = 0;
	for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
		cur[u] = i;
		int ver = e[i];
		if (d[ver] == d[u] + 1 && f[i]) {
			int t = find(ver, min(f[i], limit - flow));
			if (!t)d[ver] = -1;
			f[i] -= t, f[i ^ 1] += t, flow += t;
		}
	}
	return flow;
}
void dfs(int u, bool op) {
	if (!op)oks[u] = true;
	else okt[u] = true;
	for (int i = h[u]; ~i; i = ne[i]) {
		int ver = e[i];
		if ((!op && f[i]) || (op && f[i ^ 1])) {//正向跑选正向边，反向跑选反向边，即方向都从S到T。
			if ((!op && oks[ver]) || (op && okt[ver]))continue;
			dfs(ver, op);
		}
	}
}
/*void dfs(int u, bool st[], int op)
{
	st[u] = true;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = i ^ op, ver = e[i];
		if (f[j] && !st[ver])
			dfs(ver, st, op);
	}
}*/
int dinic() {
	int r = 0, flow;
	while (bfs())while (flow = find(S, INF))r += flow;
	return r;
}
void solve() {
	cin >> n >> m;
	S = 0, T = n - 1;
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c);
	}
	int res = 0;
	dinic();
	dfs(S, false), dfs(T, true);
	for (int x = 0; x < idx; x += 2) {
		if (!f[x] && oks[e[x ^ 1]] && okt[e[x]])res++;
	}
	cout << res << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int TT = 1;
	//cin >> TT, cin.get();
	while (TT--) {
		solve();
	}
	return 0;
}
