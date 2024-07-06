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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int>a(N, 0), s(N);
	for (int x = 1; x <= n; x++)cin >> a[x];
	s = a;

	/*vector<vector<int>>dp(N + 5, vector<int>(N + 5, 0));//爆内存

	auto rmq_init = [&]()->void {
		for (int x = 1; x <= n; x++) {
			dp[x][0] = a[x];
		}
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i++) {
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
			}
		}
	};

	auto rmq = [&](int lf, int rt)->int{
		int k = log2(rt - lf + 1);
		return min(dp[lf][k], dp[rt - (1 << k) + 1][k]);
	};

	rmq_init();*/

	for (int x = n; x >= 1; x--)if (x != n)s[x] = min(s[x], s[x + 1]);
	for (int x = 1; x <= n; x++) {
		if (x != 1)cout << ' ';
		int l = x, r = n, as = x;
		while (l < r) {
			int md = (l + r + 1) >> 1;
			if (s[md] < a[x])l = md, as = md;
			else r = md - 1;
		}
		cout << as - x - 1;
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
