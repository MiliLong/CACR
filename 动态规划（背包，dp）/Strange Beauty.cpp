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
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int a[N];
void solve() {
	int n, ma = 0, res = 0; cin >> n;
	vector<int>cnt(N, 0), f(N, 0);
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		ma = max(ma, a[x]);
		cnt[a[x]]++;
	}

	for (int x = 1; x <= ma; x++) {
		f[x] += cnt[x];
		for (int y = 2; y * x <= ma; y++) {
			f[x * y] = max(f[x * y], f[x]);
		}
	}

	for (int x = 1; x <= ma; x++)res = max(res, f[x]);

	cout << n - res << '\n';
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
