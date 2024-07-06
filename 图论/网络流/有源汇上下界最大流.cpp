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
int n, m, S, T, s, t;
int e[N], ne[N], h[N], idx, f[N];
int q[N], d[N], cur[N], A[N];
void add(int a, int b, int c, int d) {
	e[idx] = b, ne[idx] = h[a], f[idx] = d - c, h[a] = idx++;
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
	cin >> n >> m >> s >> t;
	memset(h, -1, sizeof h);
	S = 0, T = n + 1;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a, b, c, d);
		A[a] -= c, A[b] += c;
	}
	int tot = 0;
	for (int x = 1; x <= n; x++) {
		if (A[x] > 0)add(S, x, 0, A[x]), tot += A[x];
		else if (A[x] < 0)add(x, T, 0, -A[x]);
	}
	add(t, s, 0, INF);
	if (tot != dinic())cout << "No Solution";
	else {
		int res = f[idx - 1];
		f[idx - 1] = f[idx - 2] = 0;
		S = s, T = t;
		cout << res + dinic();
	}

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
