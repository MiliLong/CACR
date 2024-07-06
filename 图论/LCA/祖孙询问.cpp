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
	vector<vector<int>>eg, fa;
	vector<int>depth;
	void add(int a, int b) {eg[a].push_back(b);}

	void bfs(int root) {
		depth.insert(depth.begin(), n + 1, INF);
		depth[0] = 0; depth[root] = 1;
		queue<int>que;
		que.push(root);
		while (que.size()) {
			int t = que.front(); que.pop();

			for (auto it : eg[t]) {
				if (depth[it] > depth[t] + 1) {
					depth[it] = depth[t] + 1;
					que.push(it);
					fa[it][0] = t;
					for (int k = 1; k <= 15; k++) {
						fa[it][k] = fa[fa[it][k - 1]][k - 1];
					}
				}
			}
		}
	}

	int lca(int a, int b) {
		if (depth[a] < depth[b])swap(a, b);
		for (int k = 15; k >= 0; k--) {
			if (depth[fa[a][k]] >= depth[b])a = fa[a][k];
		}
		if (a == b)return a;
		for (int k = 15; k >= 0; k--) {
			if (fa[a][k] != fa[b][k]) {
				a = fa[a][k];
				b = fa[b][k];
			}
		}

		return fa[a][0];
	}

	LCA(int n): n(n), eg(n + 1), fa(n + 1, vector<int>(16, 0)), depth(n + 1) {};
};
void solve(int T) {
	int n, root; cin >> n;
	LCA l(40001);
	for (int x = 0; x < n; x++) {
		int a, b; cin >> a >> b;
		if (b == -1)root = a;
		else {l.add(a, b); l.add(b, a);}
	}

	l.bfs(root);

	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		int p = l.lca(a, b);
		if (p == a)cout << 1 << '\n';
		else if (p == b)cout << 2 << '\n';
		else cout << 0 << '\n';
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
