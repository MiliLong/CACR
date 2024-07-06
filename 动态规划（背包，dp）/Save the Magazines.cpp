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
void solve() {
	int n; cin >> n;
	string s; cin >> s; s = " " + s;
	int a[n + 1];
	for (int x = 1; x <= n; x++)cin >> a[x]; a[0] = 0;
	array<int, 2>f{ -INF, -INF};

	f[0] = f[1] = 0;
	for (int x = 1; x <= n; x++) {
		auto g = f;

		if (s[x] - '0' == 1) {
			f[0] = g[0] + a[x - 1];
			f[1] = max(g[0], g[1]) + a[x];
		}
		else {
			f[0] = max(g[0], g[1]);
			f[1] = -INF;
		}
	}

	cout << max(f[0], f[1]) << '\n';
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
