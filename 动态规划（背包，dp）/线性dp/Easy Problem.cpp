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
	int n; string s; cin >> n >> s;

	s = " " + s;
	vector<int>a(n + 1), dp(5, 0); dp[0] = 1e18;
	map<char, int>mp; mp['h'] = 1, mp['a'] = 2, mp['r'] = 3, mp['d'] = 4;
	for (int x = 1; x <= n; x++)cin >> a[x];

	for (int x = 1; x <= n; x++) {

		if (mp.count(s[x]) == 0)continue;
		dp[mp[s[x]]] = min(dp[mp[s[x]]] + a[x], dp[mp[s[x]] - 1]);

	}
	int ans = 1e18;
	for (int x = 1; x <= 4; x++)ans = min(ans, dp[x]);

	cout << ans << '\n';
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
