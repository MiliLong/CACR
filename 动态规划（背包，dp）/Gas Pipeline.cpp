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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int n, a, b; cin >> n >> a >> b;
	string s; cin >> s;
	s = " " + s;

	vector<vector<int>>dp(n + 1, vector<int>(3, 100000000000000000));
	dp[0][0] = b;

	for (int x = 1; x <= n; x++) {
		if (s[x] == '1') {
			dp[x][1] = dp[x - 1][1] + 2 * b + a;
		}
		else {
			dp[x][0] = min(dp[x - 1][0] + b + a, dp[x - 1][1] + 2 * a + b);
			dp[x][1] = min(dp[x - 1][0] + 2 * b + 2 * a, dp[x - 1][1] + 2 * b + a);
		}
	}

	cout << dp[n][0] << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
