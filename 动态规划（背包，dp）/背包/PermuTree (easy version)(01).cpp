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
	int n; cin >> n;
	vector eg(n + 1, vector<int>());

	for (int x = 2; x <= n; x++) {
		int i; cin >> i;
		eg[x].emplace_back(i);
		eg[i].emplace_back(x);
	}

	vector<int>siz(n + 1);
	int ans = 0;

	auto dfs = [&](auto && dfs, int u, int f)->void{
		siz[u] = 1;

		for (auto it : eg[u]) {
			if (it == f)continue;

			dfs(dfs, it, u);
			siz[u] += siz[it];
		}

		vector<bool>dp(siz[u] + 1);

		dp[0] = 1;

		for (auto it : eg[u]) {
			if (it == f)continue;

			for (int v = siz[u] - 1; v >= siz[it]; v--) {
				dp[v] = dp[v] | dp[v - siz[it]];
			}
		}


		int res = 0;

		for (int x = 0; x <= siz[u]; x++)
			if (dp[x])
				res = max(res, x * (siz[u] - 1 - x));

		ans += res;
		return;
	};

	dfs(dfs, 1, 0);

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
