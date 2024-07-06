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
int x, y, k, b;
class DigitDP {

	int dp[1000][1000], a[1000];

public:
	int dfs(int pos, int limit, int cnt) {
		if (!pos)return cnt == k;
		if (!limit && dp[pos][cnt] != -1)return dp[pos][cnt];
		int res = 0, up = limit ? a[pos] : b - 1;

		for (int x = 0; x <= up && x <= 1; x++) {
			if ((cnt == k && x == 1) || x > 1/*特判条件*/)continue;
			res += dfs(pos - 1, limit && x == up, cnt + (x == 1));
		}

		if (!limit)dp[pos][cnt] = res;
		return res;
	}

	int cal(int u) {
		memset(dp, -1, sizeof dp);
		int cnt = 0;
		while (u)a[++cnt] = u % b, u /= b;
		return dfs(cnt, 1, 0);
	}

	int operator [](int x) {
		return cal(x);
	}

};

void solve() {
	cin >> x >> y >> k >> b;
	DigitDP a;
	cout << a[y] - a[x - 1] << '\n';
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
