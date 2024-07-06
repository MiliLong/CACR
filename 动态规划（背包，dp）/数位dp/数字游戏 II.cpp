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

class DigitDP {
public:
	int dp[20][200], a[1000], hex = 10/*进制*/, mod;

	DigitDP(int n): mod(n) {};

	int dfs(int pos, int sum, int limit) {
		if (!pos)return (sum % mod == 0);
		if (!limit && dp[pos][sum] != -1)return dp[pos][sum];
		int res = 0, up = limit ? a[pos] : 9;

		for (int x = 0; x <= up; x++) {
			res += dfs(pos - 1, sum + x , limit && x == up);
		}

		if (!limit)dp[pos][sum] = res;
		return res;
	}

	int cal(int u) {
		memset(dp, -1, sizeof dp);
		int len = 0;
		while (u)a[++len] = u % hex, u /= hex;
		return dfs(len, 0, 1);
	}

	int operator [](int x) {
		return cal(x);
	}

};

void solve() {
	int a, b, n;
	while (cin >> a >> b >> n) {
		DigitDP d(n);
		cout << d[b] - d[a - 1] << '\n';
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
