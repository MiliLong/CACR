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

	int dp[20][20], a[1000], hex = 10/*进制*/;

public:
	int dfs(int pos, int pre, int limit) {
		if (!pos)return 1;
		if (!limit && dp[pos][pre] != -1/*前导为0也可记忆化*/)return dp[pos][pre];
		int res = 0, up = limit ? a[pos] : 9;

		for (int x = 0; x <= up; x++) {
			if (abs(pre - x) < 2 && pre != 10/*差小于2,上一位为0且为前导0过滤掉*/)continue;
			res += dfs(pos - 1, x == 0 && pre == 10 ? 10 : x/*继承前导0*/, limit && x == up);
		}

		if (!limit)dp[pos][pre] = res/*前导0开辟dp[][10]存储*/;
		return res;
	}

	int cal(int u) {
		memset(dp, -1, sizeof dp);
		int len = 0;
		while (u)a[++len] = u % hex, u /= hex;
		return dfs(len, 10, 1);
	}

	int operator [](int x) {
		return cal(x);
	}

};

void solve() {
	DigitDP d;
	int a, b;
	cin >> a >> b;
	cout << d[b] - d[a - 1] << '\n';
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
