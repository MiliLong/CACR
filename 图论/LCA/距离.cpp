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

class LCA {
public:
	int n;
	vector<vector<PII>>eg;
	vector<vector<int>>fa;
	vector<int>depth, dist;
	void add(int a, int b, int c) {eg[a].push_back({b, c});}

	void bfs(int root) {
		depth.insert(depth.begin(), n + 1, INF);
		depth[0] = 0; depth[root] = 1;
		dist[root] = 0;
		queue<int>que;
		que.push(root);
		while (que.size()) {
			int t = que.front(); que.pop();

			for (auto [it, w] : eg[t]) {
				if (depth[it] > depth[t] + 1) {
					depth[it] = depth[t] + 1;
					dist[it] = dist[t] + w;
					que.push(it);
					fa[it][0] = t;
					for (int k = 1; k <= 17; k++) {
						fa[it][k] = fa[fa[it][k - 1]][k - 1];
					}
				}
			}
		}
	}

	int lca(int a, int b) {
		if (depth[a] < depth[b])swap(a, b);
		for (int k = 17; k >= 0; k--) {
			if (depth[fa[a][k]] >= depth[b])a = fa[a][k];
		}
		if (a == b)return a;
		for (int k = 17; k >= 0; k--) {
			if (fa[a][k] != fa[b][k]) {
				a = fa[a][k];
				b = fa[b][k];
			}
		}

		return fa[a][0];
	}

	LCA(int n): n(n), eg(n + 1), fa(n + 1, vector<int>(18, 0)), depth(n + 1), dist(n + 1) {};
};

void solve(int T) {
	int n, m; cin >> n >> m;
	LCA L(n);
	for (int x = 0; x < n - 1; x++) {
		int a, b, c; cin >> a >> b >> c;
		L.add(a, b, c);
		L.add(b, a, c);
	}

	L.bfs(1);

	while (m--) {
		int a, b; cin >> a >> b;
		int p = L.lca(a, b);
		cout << L.dist[a] + L.dist[b] - 2 * L.dist[p] << '\n';
	}

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
