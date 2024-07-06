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
using namespace std;//求子树
void solve() {
	int n, a, b; cin >> n >> a >> b;
	vector<vector<int>>eg(n + 1);
	for (int x = 0; x < n - 1; x++) {
		int i, j; cin >> i >> j;

		eg[i].emplace_back(j);
		eg[j].emplace_back(i);

	}

	vector<int>son(n + 1, 0), Son(n + 1, 0);
	auto dfsa = [&](auto && dfsa, int u, int f) {
		int res = 1ll;

		if (eg[u].size() == 1 && u != a) {
			son[u] = 1ll;
			return res;
		}
		for (auto it : eg[u]) {
			if (it == f)continue;
			res += dfsa(dfsa, it, u);
		}
		son[u] = res;
		return res;
	};
	auto dfsb = [&](auto && dfsb, int u, int f) {
		int res = 1ll;

		if (eg[u].size() == 1 && u != b) {
			Son[u] = 1ll;
			return res;
		}
		for (auto it : eg[u]) {
			if (it == f)continue;
			res += dfsb(dfsb, it, u);
		}
		Son[u] = res;
		return res;
	};

	dfsa(dfsa, a, 0);
	dfsb(dfsb, b, 0);

	int ans = n * (n - 1ll) - son[b] * Son[a];

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
