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

int n, m;
int dist[510], g[510][510], vis[510];

int prim() {
	memset(dist, 0x3f, sizeof dist);

	int res = 0;

	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}

		if (i && dist[t] == INF)return INF;

		vis[t] = true;
		if (i)res += dist[t];

		for (int i = 1; i <= n; i++)dist[i] = min(dist[i], g[t][i]);
	}

	return res;
}
void solve() {
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;

	while (m--) {
		int u, v, w; cin >> u >> v >> w;

		g[u][v] = g[v][u] = min(g[u][v], w);
	}

	int ans = prim();
	if (ans == INF)cout << "impossible\n";
	else cout << ans << '\n';
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
