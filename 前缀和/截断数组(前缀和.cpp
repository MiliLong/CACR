#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int sum[n + 1], a[n + 1];
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		if (x == 1)sum[x] = a[x];
		else {
			sum[x] = sum[x - 1] + a[x];
		}
	}
	if (sum[n] % 3 != 0) {
		cout << 0 << endl;
		return;
	}
	long long  as = 0, cnt = 0;
	for (int x = 2; x < n; x++) {
		if (sum[x - 1] == sum[n] / 3)cnt++;//取每一点前三分之和的数量；
		if (sum[x] == sum[n] / 3 * 2)as += cnt;//判断为三分之二点则，以该点为三分之二点的种类和等于该点前三分之和cnt；
		//对每一个三分之二点的状况求和即为答案；
	}
	cout << as << endl;
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
