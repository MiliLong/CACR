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
	vector<int>w(n + 1);

	for (int x = 1; x <= n; x++)cin >> w[x];
	vector<vector<int>>eg(n + 1);

	for (int x = 0; x < n - 1; x++) {
		int u, v; cin >> u >> v;

		eg[u].emplace_back(v);
		eg[v].emplace_back(u);
	}

	vector<vector<int>>f(n + 1, vector<int>(3));

	auto dfs = [&](auto && dfs, int u, int fa)->void {
		f[u][0] = 0;
		f[u][2] = w[u];

		for (auto it : eg[u]) {
			if (it == fa)continue;
			dfs(dfs, it, u);
			f[u][0] += min(f[it][1], f[it][2]);
			f[u][2] += min({f[it][0], f[it][1], f[it][2]});
		}

		f[u][1] = 1e18;

		for (auto it : eg[u]) {
			if (it == fa)continue;
			f[u][1] = min(f[u][1], f[it][2] + f[u][0] - min(f[it][1], f[it][2]));
		}
		return;
	};

	dfs(dfs, 1, 0);
	cout << min(f[1][1], f[1][2]) << '\n';
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
