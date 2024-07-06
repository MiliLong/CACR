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
const int N = 3e4 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, st, ed, h; int dist[N]; bool vis[N];
int a[N]; map<PII, int>cs; vector<vector<int>>eg(N + 2);
bool check(int p) {
	memset(dist, INF, sizeof dist);
	memset(vis, false, sizeof vis);

	priority_queue<PII, vector<PII>, greater<PII>>heap;

	dist[st] = 0;
	heap.push({dist[st], st});
	while (heap.size()) {
		auto [dis, vir] = heap.top(); heap.pop();

		if (vis[vir])continue;//防止重复入队，否则，一个点被更新后入队，之后由于不是最短路再次被更新从而重复入队
		vis[vir] = true;

		for (auto it : eg[vir]) {

			if (a[it] > p)continue;

			int cos = cs[ {min(it, vir), max(it, vir)}];
			if (dist[it] > dist[vir] + cos) {
				dist[it] = dist[vir] + cos;
				heap.push({dist[it], it});
			}
		}
	}

	return dist[ed] <= h;
}
void solve() {
	cin >> n >> m >> st >> ed >> h; int l = 1, r = 1;
	for (int x = 1; x <= n; x++)cin >> a[x], r = max(r, a[x]);
	while (m--) {
		int x, y, z; cin >> x >> y >> z;
		if (x > y)swap(x, y);
		cs[ {x, y}] = z;
		eg[x].emplace_back(y);
		eg[y].emplace_back(x);
	}
	while (l < r) {
		int md = (l + r) >> 1;
		if (check(md))r = md;
		else l = md + 1;
	}
	if (check(l))cout << l << '\n';
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
