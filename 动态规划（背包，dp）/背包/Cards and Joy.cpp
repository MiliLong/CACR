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
void solve() {
	int n, k, ans = 0; cin >> n >> k;
	vector<int>h(k + 1);
	map<int, int>a, b;
	for (int x = 0, i; x < n * k; x++) {
		cin >> i;
		a[i]++;
	}
	for (int x = 0, i; x < n; x++) {
		cin >> i;
		b[i]++;
	}
	for (int x = 1; x <= k; x++)cin >> h[x];

	vector<vector<int>>dp(n + 1, vector<int>(n * k + 1, 0));

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n * k; y++) {
			for (int z = 1; z <= min(y, k); z++) {
				dp[x][y] = max(dp[x][y], dp[x - 1][y - z] + h[z]);
			}
		}
	}

	for (auto [id, cnt] : b) {
		ans += dp[cnt][a[id]];
	}
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
