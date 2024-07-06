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
int n, m, st, _end, ans = 0, sd[1010], ed[1010], vis[1010];

vector<int>eg[1010];

void dij(int *dist, int root) {
	for (int x = 0; x < 1010; x++)dist[x] = INF;
	memset(vis, 0, sizeof vis);
	dist[root] = 0;
	priority_queue<PII, vector<PII>, greater<PII>>heap;

	heap.push({dist[root], root});
	while (heap.size()) {
		auto [dis, vir] = heap.top(); heap.pop();
		if (vis[vir])continue;

		vis[vir] = true;

		for (auto it : eg[vir]) {
			if (dist[it] > dist[vir] + 1) {
				dist[it] = dist[vir] + 1;
				heap.push({dist[it], it});
			}
		}
	}
}
void solve() {
	cin >> n >> m >> st >> _end;
	ans = -m;
	while (m--) {
		int u, v; cin >> u >> v;

		eg[u].emplace_back(v);
		eg[v].emplace_back(u);
	}

	dij(sd, st);
	dij(ed, _end);

	for (int x = 1; x <= n - 1; x++) {
		for (int y = x + 1; y <= n; y++) {
			if (sd[x] + ed[y] + 1 >= sd[_end] && sd[y] + ed[x] + 1 >= sd[_end])ans++;
		}
	}

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
