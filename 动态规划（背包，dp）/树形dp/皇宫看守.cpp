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
	vector<vector<int>>eg(n + 1);
	vector<int>in(n + 1, 0), w(n + 1);

	for (int x = 1; x <= n; x++) {
		int i, k, m; cin >> i >> k >> m;
		w[i] = k;
		while (m--) {
			int j; cin >> j;
			in[j]++;
			eg[i].emplace_back(j);
		}
	}

	int root = -1;
	for (int x = 1; x <= n; x++)if (in[x] == 0)root = x;

	vector<array<int, 3>>f(n + 1);
	auto dfs = [&](auto && dfs, int u)->void{
		f[u][0] = 0;
		f[u][2] = w[u];

		for (auto it : eg[u]) {
			dfs(dfs, it);
			f[u][0] += min(f[it][1], f[it][2]);
			f[u][2] += min({f[it][0], f[it][1], f[it][2]});
		}

		f[u][1] = 1e18;

		for (auto it : eg[u]) {
			f[u][1] = min(f[u][1], f[it][2] + f[u][0] - min(f[it][1], f[it][2]));
		}
		return;
	};


	dfs(dfs, root);
	cout << min(f[root][1], f[root][2]) << '\n';
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
