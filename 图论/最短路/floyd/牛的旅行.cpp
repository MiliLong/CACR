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
using ll = long long;
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n;
PII p[N];
char g[N][N];
double maxd[N], dist[N][N], _INF = 1e20;

double gt(PII a, PII b) {
	int nx = a.ff - b.ff, nb = a.ss - b.ss;
	return sqrt(nx * nx + nb * nb);
}

void solve() {
	cin >> n;

	for (int x = 0; x < n; x++)cin >> p[x].ff >> p[x].ss;

	for (int x = 0; x < n; x++)cin >> g[x];

	for (int x = 0; x < n; x++)
		for (int y = 0; y <= n; y++)
			if (x != y)
				if (g[x][y] == '1')
					dist[x][y] = gt(p[x], p[y]);
				else
					dist[x][y] = _INF;

	for (int k = 0; k < n; k++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				dist[x][y] = min(dist[x][y], dist[x][k] + dist[k][y]);

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if (dist[x][y] >= _INF)
				continue;
			else
				maxd[x] = max(maxd[x], dist[x][y]);

	double res1 = 0, res2 = _INF;

	for (int x = 0; x < n; x++)
		res1 = max(res1, maxd[x]);

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			if (dist[x][y] >= _INF)
				res2 = min(res2, gt(p[x], p[y]) + maxd[x] + maxd[y]);

	cout << fixed << setprecision(6) << max(res1, res2) << '\n';

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
