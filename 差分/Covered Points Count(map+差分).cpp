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
void solve() {
	int n; cin >> n;

	map<int, int>mp;
	vector<PII>a(n); int as[n + 1];
	memset(as, 0, sizeof as);
	for (int x = 0; x < n; x++) {
		auto &[u, v] = a[x];

		cin >> u >> v;
		mp[u]++, mp[v + 1]--;
	}

	sort(all(a));

	int f = 0, ct = 0;
	for (auto [u, c] : mp) {
		as[ct] += u - f;
		f = u;
		ct += c;
	}

	for (int x = 1; x <= n; x++)cout << as[x] << ' ';
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
