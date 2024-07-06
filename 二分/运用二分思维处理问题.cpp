#include<bits/stdc++.h>
using namespace std;
int a[100003], mid = 0, l, r, m, n;
int check(int mm) {
	int sum = 1, f = a[0] + mm;
	for (int x = 1; x < n; x++) {
		if (a[x] >= f) {
			sum++;
			f = a[x] + mm;
		}
	}
	if (sum >= m)	return 1;
	else return 0;
}
void solve() {
	cin >> n >> m;
	for (int x = 0; x < n; x++)cin >> a[x];
	sort(a, a + n);
	l = 0, r = a[n - 1] - a[0];
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
//	cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
