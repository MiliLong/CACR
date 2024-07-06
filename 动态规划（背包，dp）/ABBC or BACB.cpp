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
const int N = 1e6 + 10, INF = 1e17;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	string s; cin >> s;
	int len = s.size();
	s = "B" + s;
	vector<int>cnt(len + 3, 0), id(len + 3, 0);
	int idx = 0;
	for (int x = 1; x <= len; x++) {
		if (s[x] == 'A' && s[x - 1] == 'B')id[x] = ++idx;
		else if (s[x] == 'A')id[x] = id[x - 1];
		if (s[x] == 'A')cnt[id[x]]++;
	}
	int res = 0, f = 0;
	vector<vector<int>>dp(len + 2, vector<int>(2));
	dp[0][0] = 0, dp[0][1] = -INF;
	for (int x = 1; x <= len; x++) {
		if (s[x] == 'A')continue;
		dp[x][1] = cnt[id[x + 1]] + max(dp[f][1], dp[f][0]);
		dp[x][0] = max(dp[f][0] + cnt[id[x - 1]], dp[f][1]);
		f = x;
	}
	cout << max(dp[f][0], dp[f][1]) << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int TT = 1;
	cin >> TT, cin.get();
	while (TT--) {
		solve();
	}
	return 0;
}
