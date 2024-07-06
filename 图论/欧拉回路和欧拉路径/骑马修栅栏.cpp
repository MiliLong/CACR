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
class cmp {
public:
	bool operator()(const PII&a, const PII&b) {
		return a.ff > b.ff;
	}
};
vector<priority_queue<PII, vector<PII>, cmp>>eg(N);
int m, ans[N], cnt, used[N], st = 1;
void dfs(int u) {
	while (eg[u].size()) {
		auto [v, id] = eg[u].top();
		eg[u].pop();
		if (used[id]) {
			continue;
		}
		used[id] = true;
		dfs(v);
	}
	ans[cnt++] = u;
}
void solve(int T) {
	cin >> m;
	for (int x = 1; x <= m; x++) {
		int u, v; cin >> u >> v;
		eg[u].push({v, x});
		eg[v].push({u, x});
	}

	while (!eg[st].size())st++;
	for (int x = 1; x <= N; x++) {
		if (eg[x].size() % 2) {
			st = x;
			break;
		}
	}
	dfs(st);
	for (int x = cnt - 1; x >= 0; x--)cout << ans[x] << '\n';
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
