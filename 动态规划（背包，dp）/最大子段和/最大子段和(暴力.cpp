#include<bits/stdc++.h>
using namespace std;
//暴力遍历所有区间头尾，通过前缀和快速计算； 
void solve() {
	int n;
	cin >> n ;
	int s[n + 1], a[n + 1];
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		if (x == 1)s[x] = a[x];
		else s[x] = s[x - 1] + a[x];
	}
	int maxx = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = x; y <= n; y++) {
			int md = s[y] - s[x] + a[x];
			maxx = max(md, maxx);
		}
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
