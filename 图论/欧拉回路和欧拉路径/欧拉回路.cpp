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
using LL = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int type, n, m;
vector<vector<PII>>eg(N);
int din[N], dout[N], ans[N], cnt, used[N];
void dfs(int u) {
	while (eg[u].size()) {
		auto [v, id] = eg[u].back();
		eg[u].pop_back();
		if (used[abs(id)]) {
			continue;
		}
		used[abs(id)] = true;
		dfs(v);
		ans[cnt++] = id;
	}
}
void solve(int T) {
	cin >> type >> n >> m;
	for (int x = 1; x <= m; x++) {
		int u, v; cin >> u >> v;
		eg[u].emplace_back(v, x);
		if (type == 1)eg[v].emplace_back(u, -x);
		din[v]++, dout[u]++;
	}
	if (type == 1) {
		for (int x = 1; x <= n; x++)
			if ((din[x] + dout[x]) & 1) {
				cout << no;
				return;
			}
	} else {
		for (int x = 1; x <= n; x++)
			if (din[x] != dout[x]) {
				cout << no;
				return;
			}
	}

	for (int x = 1; x <= n; x++) {
		if (!eg[x].empty()) {
			dfs(x);
			break;
		}
	}

	if (cnt < m) {
		cout << no;
		return;
	}

	cout << yes;

	for (int x = cnt - 1; x >= 0; x--)cout << ans[x] << ' ';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
