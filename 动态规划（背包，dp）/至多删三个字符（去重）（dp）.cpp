#include<bits/stdc++.h>
using namespace std;
long long int dp[1000003][4];
void solve() {
	char s[1000003];
	cin >> s + 1;
	int len = strlen(s + 1);
	dp[0][0] = 1;
	for (int x = 1; x <= len; x++) {
		for (int y = 0; y <= 3; y++) {
			dp[x][y] += dp[x - 1][y] ;
			if (y)dp[x][y] += dp[x - 1][y - 1];
			for (int z = x - 1; z >= 1 && x - z <= y; z--) {
				if (s[z] == s[x]) {
					dp[x][y] -= dp[z - 1][y - (x - z)];//减去删和不删情况的重复，若不满足条件显然不重复，若满足相当于重复相同位置前，再删（y - (x - z)）的dp，因为这是还需要删的数量。 
					break;
				}
			}
		}
	}
	cout << dp[len][0] + dp[len][1] + dp[len][2] + dp[len][3];
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
