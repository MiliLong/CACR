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
using ll = long long;
const int N = 1e6 + 10, INF = 1e18;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
array<array<int, 3>, 2>f{ -INF, -INF, -INF, -INF, -INF, -INF};
void solve() {
	int n, ans = 0; cin >> n;

	int a[n + 1], b[n + 1]; a[0] = b[0] = 0;
	for (int x = 1; x <= n; x++)cin >> a[x];
	for (int x = 1; x <= n; x++)cin >> b[x];

	f[0][0] = 0;
	for (int x = 1; x <= n; x++) {
		auto g = f;

		if (b[x]) {
			f[0][0] = g[0][0] + a[x - 1]; //原本有帽子,当前没帽子,帽子去了左边
			f[0][1] = max({g[0][0], g[1][0], g[1][2]}); //原本有帽子,当前没帽子,帽子去了右边
			f[1][0] = max({g[0][0], g[1][0], g[1][2]}) + a[x]; //原本有帽子,当前也有帽子,帽子哪里都没去,还是自己原本的帽子
			f[1][1] = max(g[0][1], g[1][1]) + a[x]; //原本有帽子,当前也有帽子,帽子去了右边,当前戴的是左边的帽子
			f[1][2] = -INF;

		}
		else {
			f[0][0] = max({g[0][0], g[1][0], g[1][2]}); //原本没帽子,当前没帽子
			f[1][2] = max(g[0][1], g[1][1]) + a[x]; //原本没帽子,当前有帽子,帽子来自左边
			f[0][1] = f[1][0] = f[1][1] = -INF;
		}
	}
	cout << max({f[0][0], f[1][2], f[1][0]}) << '\n';
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
