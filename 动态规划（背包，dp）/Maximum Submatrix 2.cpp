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
const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, res = 0;
int a[N][N], cnt[N][N], ct[N];
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++) {
			char c; cin >> c;
			a[x][y] = c - '0';
		}

	for (int x = 1; x <= n; x++)
		for (int y = m; y >= 1; y--) {
			if (a[x][y] == 1)cnt[x][y] = cnt[x][y + 1] + 1;
			else cnt[x][y] = 0;
		}

	for (int y = 1; y <= m; y++) {
		for (int x = 1; x <= n; x++)ct[x] = cnt[x][y];
		sort(ct + 1, ct + 1 + n);
		for (int x = 1; x <= n; x++)
			res = max(res, ct[x] * (n - x + 1));
	}
	cout << res << '\n';
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
