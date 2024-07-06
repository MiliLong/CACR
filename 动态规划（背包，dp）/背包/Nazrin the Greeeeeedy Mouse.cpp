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
using ll = long long;
const int N = 3e2 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, a[N], b[N], f[N][N][N], g[100010][N], siz[1000000];
void solve() {
	cin >> n >> m;

	for (int x = 1; x <= n; x++)cin >> a[x] >> b[x];
	for (int x = 1; x <= m; x++)cin >> siz[x];

	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
			for (int s = 0; s <= 200; s++) {
				f[l][r][s] = f[l][r - 1][s];
				if (a[r] <= s)f[l][r][s] = max(f[l][r][s], f[l][r - 1][s - a[r]] + b[r]);
			}

	for (int x = max(1ll, m - 200); x <= m; x++)
		for (int i = 1; i <= n; i++) {
			g[x][i] = g[x - 1][i];
			for (int j = 0; j < i; j++)
				g[x][i] = max(g[x][i], g[x - 1][j] + f[j + 1][i][siz[x]]);

		}

	cout << g[m][n] << '\n';
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
