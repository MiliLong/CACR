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
int e[N], ne[N], h[N], idx, f[N];
int q[N], d[N], cur[N];
void add(int a, int b, int c) {
	e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
	e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}
bool bfs() {
	memset(d, -1, sizeof d);
	q[0] = S, d[S] = 0, cur[S] = h[S];
	int hh = 0, tt = 0;
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i]) {
			int ver = e[i];
			if (d[ver] == -1 && f[i]) {
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
int dinic() {
	int r = 0, flow;
	while (bfs())while (flow = find(S, INF))r += flow;
	return r;
}
void solve() {
	cin >> m >> n;
	memset(h, -1, sizeof h);
	S = 0, T = n + 1;
	for (int x = 1; x <= m; x++)add(S, x, 1);
	for (int x = m + 1; x <= n; x++)add(x, T, 1);
	int a, b;
	while (cin >> a >> b, a != -1) {
		add(a, b, 1);
	}
	cout << dinic() << '\n';
	for (int x = 0; x < idx; x += 2) {
		if (e[x] <= n && e[x] > m && !f[x]) {
			cout << e[x ^ 1] << ' ' << e[x] << '\n';
		}
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
