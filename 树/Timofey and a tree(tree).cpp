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
//#define int long long
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int>a(n + 1, 0), b(n + 1, 0);
	int ege = 0;
	vector<PII>q;

	for (int x = 0; x < n - 1; x++) {
		int i, j; cin >> i >> j;

		q.emplace_back(i, j);

	}

	for (int x = 1; x <= n; x++)cin >> a[x];

	for (auto [i, j] : q) {
		if (a[i] != a[j]) {
			ege++;
			b[i]++, b[j]++;
		}
	}

	bool ok = false; int ans = -1;
	for (int x = 1; x <= n; x++) {
		if (ege == b[x]) {
			ok = true, ans = x;
			break;
		}
	}
	if (ok)cout << yes << ans << '\n';
	else cout << no;

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
