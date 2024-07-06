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
int n, m, sum = 0, res = 1e18;
vector<array<int, 4>>edge;
vector<vector<PII>>eg;
vector<array<int, 18>>fa, d1, d2;
vector<int>p, depth;
int find(int u) {
	if (u != p[u])p[u] = find(p[u]);
	return p[u];
}
void merge(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa == fb)return;
	p[fa] = fb;
}
bool same(int a, int b) {
	if (find(a) == find(b))return true;
	return false;
}
void kruskal() {
	eg.resize(n + 1);
	p.resize(n + 1);
	for (int x = 1; x <= n; x++)p[x] = x;
	sort(all(edge));

	for (auto &[w, u, v, used] : edge) {
		if (same(u, v))continue;
		sum += w;
		used = true;
		eg[u].emplace_back(v, w);
		eg[v].emplace_back(u, w);
		merge(u, v);
	}
}

void bfs() {
	depth.resize(n + 1, INF);
	fa.resize(n + 1), d1.resize(n + 1), d2.resize(n + 1);
	depth[0] = 0, depth[1] = 1;
	queue<int>que;
	que.push(1);
	while (que.size()) {
		int t = que.front(); que.pop();

		for (auto [it, w] : eg[t]) {
			if (depth[it] > depth[t] + 1) {
				depth[it] = depth[t] + 1;
				que.push(it);

				fa[it][0] = t;
				d1[it][0] = w, d2[it][0] = -INF;

				for (int k = 1; k <= 17; k++) {
					int anc = fa[it][k - 1];
					fa[it][k] = fa[anc][k - 1];

					int dis[4] = {d1[it][k - 1], d2[it][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
					d1[it][k] = -INF, d2[it][k] = -INF;
					for (int x = 0; x < 4; x++) {
						int d = dis[x];
						if (d > d1[it][k])d2[it][k] = d1[it][k], d1[it][k] = d;
						else if (d != d1[it][k] && d > d2[it][k])d2[it][k] = d;
					}
				}
			}
		}
	}

}

int lca(int a, int b, int w) {

	static int dis[N * 2];
	int cnt = 0;
	if (depth[a] < depth[b])swap(a, b);

	for (int k = 16; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b]) {
			dis[++cnt] = d1[a][k];
			dis[++cnt] = d2[a][k];
			a = fa[a][k];
		}
	}

	if (a != b) {
		for (int k = 16; k >= 0; k--) {
			if (fa[a][k] != fa[b][k]) {
				dis[++cnt] = d1[a][k];
				dis[++cnt] = d2[a][k];
				dis[++cnt] = d1[b][k];
				dis[++cnt] = d2[b][k];
				a = fa[a][k];
				b = fa[b][k];
			}
		}
		dis[++cnt] = d1[a][0];
		dis[++cnt] = d1[b][0];
	}

	int dis1 = -INF, dis2 = -INF;

	for (int x = 1; x <= cnt; x++) {
		if (dis[x] > dis1)dis2 = dis1, dis1 = dis[x];
		else if (dis[x] != dis1 && dis[x] > dis2)dis2 = dis[x];
	}

	if (w > dis1)return w - dis1;
	if (w > dis2)return w - dis2;
	return INF;
}
void solve(int T) {
	cin >> n >> m;
	edge.resize(m);

	for (auto &[w, u, v, used] : edge) {
		cin >> u >> v >> w;
		used = false;
	}

	kruskal();
	bfs();

	for (auto [w, u, v, used] : edge) {
		if (!used) {
			res = min(res, sum + lca(u, v, w));
		}
	}

	cout << res << '\n';
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
