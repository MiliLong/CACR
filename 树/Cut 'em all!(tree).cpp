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
	vector<vector<int>>eg(n + 1);
	for (int x = 0; x < n - 1; x++) {
		int i, j; cin >> i >> j;

		eg[i].emplace_back(j);
		eg[j].emplace_back(i);
	}
	bool ok = true; int ans = 0;
	if (n % 2 == 1)ok = false;
	auto dfs = [&](auto && dfs, int u, int f)->int {
		if (eg[u].size() == 1 && u != 1)return 1;
		int res = 1;
		for (auto it : eg[u]) {
			if (it == f)continue;
			res += dfs(dfs, it, u);
		}
		if (res % 2 == 0) {
			ans++;
		}
		return res;
	};
	dfs(dfs, 1, 0);
	if (ok)cout << ans - 1 << '\n';
	else cout << -1 << '\n';
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
