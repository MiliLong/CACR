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
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, a[N], sum[N], ans = 0;
bitset<N>f;

void solve() {
	cin >> n;
	for (int x = 1; x <= n; x++)cin >> a[x];
	for (int x = 1; x <= 2 * n; x++)sum[x] = sum[x - 1] + a[x];

	f[1] = 1;
	for (int x = 1; x <= 2 * n; x++) {
		f |= (f << a[x]);
		if (f[x]) {
			ans = max(ans, sum[x] - x + 1);
			f[x] = 0;
		}
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
