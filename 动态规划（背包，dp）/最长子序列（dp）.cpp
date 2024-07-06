#include<bits/stdc++.h>
using namespace std;
//对所有序列结束位置取其最优的长度；
void solve() {
	int n, ma = 0;
	cin >> n;
	int a[n + 1], dp[n + 1];
	dp[1] = 1;
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		dp[x] = 1;
		for (int z = 1; z < x; z++) {
			if (a[x] > a[z]) {
				dp[x] = max(dp[x], dp[z] + 1);
				//显然这一状态由前一尾部小于该值的转移而得；
				//其相当于找到以此为结尾的前一个倒数第二个结尾的状态；
			}
		}
		ma = max(ma, dp[x]);
	}
	cout << ma;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
