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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, c;
int d[N][__lg(N)], a[N], f[N];
void rmq_init() {
	for (int x = 1; x <= n; x++) {
		d[x][0] = a[x];
	}

	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			d[i][j] = min(d[i][j - 1], d[i + (1 << j - 1)][j - 1]);
		}
	}
}

int query(int l, int r) {
	int k = __lg(r - l + 1);
	return min(d[l][k], d[r - (1 << k) + 1][k]);
}
void solve() {
	cin >> n >> c;
	for (int x = 1; x <= n; x++)cin >> a[x];
	rmq_init();

	for (int x = 1; x <= n; x++) {
		f[x] = f[x - 1];
		if (x >= c) {
			f[x] = max(f[x], f[x - c] + query(x - c + 1, x));
		}
	}

	cout << f[n] << '\n';
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
