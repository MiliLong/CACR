#include<bits/stdc++.h>
using namespace std;
//对于每一位置，显然都能有许多以该位置为结尾的区间，所有位置的所有区间和等于总子区间，
//那么可以求以每个位置为结尾区间中的最大sum为这个位置的dp值，之后再求所有位置dp的最大就行；
void solve() {
	int n;
	cin >> n ;
	int a[n + 1], dp[n + 1];
	int maxx = 0;
	dp[0] = 0;//初始态，也可直接设定dp[1]的状态为a[1]; 
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		if (dp[x - 1] > 0)dp[x] = dp[x - 1] + a[x];//若前一项dp大于0显然无论x项正负dp[x] = dp[x - 1] + a[x]最优；
		else {
			dp[x] = a[x];//反之，不如不加；
		}
		maxx = max(dp[x], maxx);
		//a[x]为结尾，a[x]是必须加的！！！；
	}
	cout << maxx;
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
