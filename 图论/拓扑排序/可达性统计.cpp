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
const int N = 4e4 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, din[N];
vector<int>tp;
bitset<N>ans[N];
vector<vector<int>>eg(N);
void topsort() {
	queue<int>que;
	for (int x = 1; x <= n; x++)
		if (!din[x])que.push(x);

	while (que.size()) {
		int t = que.front(); que.pop();
		tp.emplace_back(t);
		for (auto it : eg[t])
			if (!(--din[it]))que.push(it);
	}
}
void solve(int T) {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		eg[b].emplace_back(a);
		din[a]++;
	}
	topsort();
	for (int x = 1; x <= n; x++)ans[x][x] = 1;
	for (int x = 0; x < n; x++) {
		int u = tp[x];
		for (auto it : eg[u]) {
			ans[it] |= ans[u];
		}
	}
	for (int x = 1; x <= n; x++)cout << ans[x].count() << '\n';
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
