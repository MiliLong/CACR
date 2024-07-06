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

class Tarjan {
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
public:
	int n;
	vector<vector<PII>>eg, query;
	vector<int>dist, res, vis;
	DSU d;

	void add(int a, int b, int c) {
		eg[a].push_back({b, c});
	}

	void dfs(int u, int f) {
		if (u == 1)dist[u] = 0;
		for (auto [it, w] : eg[u]) {
			if (it == f)continue;
			dist[it] = dist[u] + w;
			dfs(it, u);
		}
	}

	void tarjan(int u) {
		vis[u] = 1;

		for (auto [it, w] : eg[u]) {
			if (!vis[it]) {
				tarjan(it);
				d.merge(u, it);
			}
		}

		for (auto [v, id] : query[u]) {
			if (vis[v] == 2) {
				int lca = d.find(v);
				res[id] = dist[u] + dist[v] - 2 * dist[lca];
			}
		}

		vis[u] = 2;
	}

	Tarjan(int n, int m): n(n), eg(n + 1), query(n + 1), dist(n + 1), res(m + 1) , vis(n + 1, 0), d(n) {};
};
void solve(int T) {
	int n, m; cin >> n >> m;
	Tarjan t(n, m);

	for (int x = 0; x < n - 1; x++) {
		int a, b, c; cin >> a >> b >> c;
		t.add(a, b, c);
		t.add(b, a, c);
	}

	for (int x = 1; x <= m; x++) {
		int a, b; cin >> a >> b;
		t.query[a].push_back({b, x});
		t.query[b].push_back({a, x});
	}

	t.dfs(1, -1);
	t.tarjan(1);

	for (int x = 1; x <= m; x++)cout << t.res[x] << '\n';

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
