#include <iostream>
#include <cstring>
using namespace std;
const int N = 40010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16];  // depth是节点在树的深度, fa[i][j]表示, i 上方的 2^j 的节点编号
int n, m;
int q[N];  // 队列

void add(int a, int b) {
	e[ ++ idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs(int root) {
	memset(depth, 0x3f, sizeof depth);  // 初始化深度, 用来判断该点是否更新过
	depth[0] = 0, depth[root] = 1;  // depth[0] 是哨兵, 表示跳出了树

	q[0] = root;
	int hh = 0, tt = 0;
	while (hh <= tt) {
		int t = q[hh ++];
		for (int i = h[t]; i; i = ne[i]) {
			int j = e[i];
			if (depth[j] > depth[t] + 1) {  // 判断是否被搜索过
				q[ ++ tt] = j;

				depth[j] = depth[t] + 1;
				fa[j][0] = t;  // 直接赋值父节点
				for (int k = 1; k <= 15; k ++)
					fa[j][k] = fa[fa[j][k - 1]][k - 1];  // 间接求出祖宗节点
			}
		}
	}
}

int lca(int a, int b) {
	// 为了方便操作, 让 节点a 变为深度较大的那个节点
	if (depth[a] < depth[b]) swap(a, b);
	// 1. a, b 先跳到同一深度
	for (int k = 15; k >= 0; k --)
		if (depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	if (a == b) return a;  // 如果现在重叠了, 那么该点就是两个点的最近公共祖先
	// 2. a, b同时向上跳, 跳到最近公共祖先的下一层
	for (int k = 15; k >= 0; k --)
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	// 返回 a或b 的父亲节点, 就是 a, b 的最近公共祖先
	return fa[a][0];
}

int main() {
	cin >> n;
	int root;
	for (int i = 0; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		if (b == -1) root = a;
		else add(a, b), add(b, a);
	}
	bfs(root); // 预处理 fa数组 和 depth 数组

	cin >> m;
	while (m --) {
		int a, b;
		cin >> a >> b;
		int p = lca(a, b);
		if (p == a) cout << "1\n";
		else if (p == b) cout << "2\n";
		else cout << "0\n";
	}
	return 0;
}