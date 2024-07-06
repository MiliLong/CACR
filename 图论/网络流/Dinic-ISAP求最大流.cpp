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
int n, m, S, T;
int h[N], e[N], ne[N], f[N], idx;
int q[N], d[N], cur[N];
void add(int a, int b, int c) {
	e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
	e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}
int bfs() {
	int hh = 0, tt = 0;
	memset(d, -1, sizeof d);
	q[0] = S, d[S] = 0, cur[S] = h[S];
	while (hh <= tt) {
		int t = q[hh++];
		for (int it = h[t]; ~it; it = ne[it]) {
			int ver = e[it];
			if (d[ver] == -1 && f[it]) {
				d[ver] = d[t] + 1;
				cur[ver] = h[ver];
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
	for (int it = cur[u]; ~it && flow < limit; it = ne[it]) {
		cur[u] = it;
		int ver = e[it];
		if (d[ver] == d[u] + 1 && f[it]) {
			int t = find(ver, min(limit - flow, f[it]));
			if (!t)d[ver] = -1;
			f[it] -= t, f[it ^ 1] += t, flow += t;
		}
	}
	return flow;
}
int dinic() {
	int r = 0, flow;
	while (bfs())while (flow = find(S, INF))r += flow;
	return r;
}
void solve() {
	cin >> n >> m >> S >> T;
	memset(h, -1, sizeof h);
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w);
	}
	cout << dinic() << '\n';
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
