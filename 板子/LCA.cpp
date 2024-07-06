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