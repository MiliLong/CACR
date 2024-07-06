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
	int r, n, ans = 0, mx = -INF; cin >> r >> n;
	vector<int>f(n + 1, 0);
	vector<array<int, 3>>a(n + 1);
	for (int x = 1; x <= n; x++) {
		auto &[t, u, v] = a[x];
		cin >> t >> u >> v;
	}
	a[0] = {0, 1, 1};
	for (int x = 1; x <= n; x++) {
		for (int y = x - 1; y >= max(0ll, x - 2 * r - 20); y--) {
			if (a[x][0] - a[y][0] >= abs(a[x][1] - a[y][1]) + abs(a[x][2] - a[y][2]) && (f[y] || !y))
				f[x] = max(f[x], f[y] + 1);
		}
		f[x] = max(f[x], mx + 1);
		ans = max(ans, f[x]);
		if (x >= 2 * r)mx = max(mx, f[x - 2 * r]);
	}

	cout << ans << '\n';
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
