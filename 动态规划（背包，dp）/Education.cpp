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
void solve() {
	int n, c; cin >> n >> c;
	vector<int>a(n + 1), b(n);
	vector<PII>f(n + 1, {0, 0});

	for (int x = 1; x <= n; x++)cin >> a[x];
	for (int x = 1; x < n; x++)cin >> b[x];

	int t = 0, cnt = 0, res = 1e18;
	for (int x = 1; x <= n; x++) {
		f[x] = {t, cnt};
		res = min(res, t + (c - cnt - 1) / a[x] + 1);
		if (cnt < b[x]) {
			t += (b[x] - cnt - 1) / a[x] + 1;
			cnt += ((b[x] - cnt - 1) / a[x] + 1) * a[x];
		}
		cnt -= b[x];
		t++;
	}

	cout << res << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
