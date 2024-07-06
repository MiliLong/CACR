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
int dp[11][11], a[20];

int dfs(int pos, int pre, int limit) {
	if (!pos)return 1;
	if (!limit && dp[pos][pre] != -1)return dp[pos][pre];
	int res = 0, up = limit ? a[pos] : 9;

	for (int x = 0; x <= up; x++) {
		if (x == 4 || (x == 2 && pre == 6))continue;
		res += dfs(pos - 1, x, limit && x == up);
	}

	if (!limit)dp[pos][pre] = res;
	return res;
}
int cal(int u) {
	memset(dp, -1, sizeof dp);
	int cnt = 0;
	while (u)a[++cnt] = u % 10, u /= 10;
	return dfs(cnt, 0, 1);
}
void solve() {
	int n, m;

	while (cin >> n >> m && (n || m)) {
		cout << cal(m) - cal(n - 1) << '\n';
	}

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
