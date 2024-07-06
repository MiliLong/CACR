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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int dp[20][20][20][20][2], a[1000];
int dfs(int pos, int limit, int cnt5, int cnt7, int c7, int ok) {
	if (!pos)return cnt5 + cnt7 * 3 + ok * 300;
	if (!limit && dp[pos][cnt5][cnt7][c7][ok] != -1)return dp[pos][cnt5][cnt7][c7][ok];
	int res = 0, up = limit ? a[pos] : 9;

	for (int x = 0; x <= up; x++) {
		int n_c = x == 7 ? c7 + 1 : 0;
		res += dfs(pos - 1, limit && (x == up), cnt5 + (x == 5), cnt7 + (x == 7), n_c, ok || n_c == 7);
	}

	if (!limit)dp[pos][cnt5][cnt7][c7][ok] = res;
	return res;
}

int cal(int u) {
	int len = 0;
	while (u)a[++len] = u % 10, u /= 10;
	return dfs(len, 1, 0, 0, 0, 0);
}
void solve() {
	int x, y; cin >> x >> y;
	cout << cal(y) - cal(x - 1) << '\n';
}
signed main () {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
