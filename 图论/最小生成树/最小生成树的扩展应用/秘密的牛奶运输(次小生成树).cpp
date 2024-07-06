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
struct DSU {
	int n, cnt;
	vector<int> p, siz;
	DSU(int n) : n(n), cnt(n), p(n + 1), siz(n + 1, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int find(int x) {
		if (x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;

		cnt--;
		siz[x] += siz[y];
		p[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};
void solve() {
	int n, m; cin >> n >> m;
	vector<array<int, 4>>eg(m);
	vector<vector<PII>>edge(n + 1), dist(n + 1, vector<PII>(n + 1));
	for (int x = 0; x < m; x++) {
		auto &[w, u, v, ok] = eg[x];
		cin >> u >> v >> w;
		ok = false;
	}
	sort(all(eg));
	int sum = 0;
	DSU d(n);
	set<int>st;
	for (auto &[w, u, v, ok] : eg) {
		if (d.same(u, v))continue;
		sum += w;
		d.merge(u, v);
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
		st.insert(u), st.insert(v);
		ok = true;
	}

	auto dfs = [&](auto && dfs, int u, int f, int ma1, int ma2, vector<PII> &dist)->void {
		auto &[m1, m2] = dist[u];
		m1 = ma1, m2 = ma2;

		for (auto [it, w] : edge[u]) {
			if (it == f)continue;
			if (w > ma1) {ma2 = ma1, ma1 = w;}
			else if (w < ma1 && w > ma2) {ma2 = w;}
			dfs(dfs, it, u, ma1, ma2, dist);
		}

	};

	for (auto it : st)dfs(dfs, it, -1, 0, 0, dist[it]);
	int ans = 1e18;

	for (auto [w, u, v, ok] : eg) {
		if (ok)continue;
		auto [ma1, ma2] = dist[u][v];
		if (ma1 < w && ma1)ans = min(ans, sum + w - ma1 );
		else if (ma2 < w && ma2) ans = min(ans, sum + w - ma2 );
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
