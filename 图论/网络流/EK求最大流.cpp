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
int n, m, s, t;
int h[N], e[N], ne[N], f[N], idx;
int q[N], d[N], pre[N];
bool st[N];
void add(int a, int b, int c) {
	e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
	e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
bool bfs() {
	int hh = 0, tt = 0;
	memset(st, false, sizeof st);
	q[0] = s, st[s] = true, d[s] = INF;
	while (hh <= tt) {
		int tp = q[hh++];
		for (int it = h[tp]; ~it; it = ne[it]) {
			int ver = e[it];
			if (!st[ver] && f[it]) {
				st[ver] = true;
				d[ver] = min(f[it], d[tp]);
				pre[ver] = it;
				if (ver == t)return true;
				q[++tt] = ver;
			}
		}
	}
	return false;
}
int EK() {
	int res = 0;
	while (bfs()) {
		res += d[t];
		for (int x = t; x != s; x = e[pre[x] ^ 1]) {
			f[pre[x]] -= d[t], f[pre[x] ^ 1] += d[t];
		}
	}
	return res;
}
void solve() {
	cin >> n >> m >> s >> t;
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	cout << EK() << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
