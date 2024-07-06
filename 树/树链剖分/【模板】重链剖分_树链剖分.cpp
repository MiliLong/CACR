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
int n, m, R, P, a[N];
vector<vector<int>>eg;
int w[N], cnt, sz[N], son[N];
int id[N], top[N], fa[N], dep[N];
struct Tree {
	int l, r;
	int add, sum;
} tr[N * 4];

void dfs1(int u, int f, int depth) {
	sz[u] = 1, fa[u] = f, dep[u] = depth;

	for (auto it : eg[u]) {
		if (it == f)continue;
		dfs1(it, u, depth + 1);
		sz[u] += sz[it];
		if (sz[it] > sz[son[u]])son[u] = it;
	}
}

void dfs2(int u, int t) {
	id[u] = ++cnt, w[cnt] = a[u], top[u] = t;
	if (!son[u])return;
	dfs2(son[u], t);
	for (auto it : eg[u]) {
		if (it == fa[u] || it == son[u])continue;
		dfs2(it, it);
	}
}

void pushup(int u) {
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
	auto &r = tr[u], &lf = tr[u << 1], &rt = tr[u << 1 | 1];
	if (r.add) {
		lf.add += r.add, lf.sum += r.add * (lf.r - lf.l + 1);
		rt.add += r.add, rt.sum += r.add * (rt.r - rt.l + 1);
		r.add = 0;
	}
}

void build(int u, int l, int r) {
	tr[u] = {l, r, 0, w[r]};
	if (l == r)return;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, int k) {
	if (l <= tr[u].l && r >= tr[u].r) {
		tr[u].add += k;
		tr[u].sum += k * (tr[u].r - tr[u].l + 1);
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)modify(u << 1, l, r, k);
	if (mid < r)modify(u << 1 | 1, l, r, k);
	pushup(u);
}

int query(int u, int l, int r) {
	if (l <= tr[u].l && r >= tr[u].r)return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	int res = 0;
	if (l <= mid)res += query(u << 1, l, r);
	if (mid < r)res += query(u << 1 | 1, l, r);
	return res % P;
}

void update_path(int u, int v, int k) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		modify(1, id[top[u]], id[u], k);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	modify(1, id[v], id[u], k);
}

void update_tree(int u, int k) {
	modify(1, id[u], id[u] + sz[u] - 1, k);
}

int query_path(int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]])swap(u, v);
		res += query(1, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v])swap(u, v);
	res += query(1, id[v], id[u]);
	return res % P;
}

int  query_tree(int u) {
	return query(1, id[u], id[u] + sz[u] - 1) % P;
}

void solve() {
	cin >> n >> m >> R >> P; eg.resize(n + 1);
	for (int x = 1; x <= n; x++)cin >> a[x];
	for (int x = 1; x <= n - 1; x++) {
		int u, v; cin >> u >> v;
		eg[u].emplace_back(v);
		eg[v].emplace_back(u);
	}
	dfs1(R, -1, 1);
	dfs2(R, R);
	build(1, 1, n);
	while (m--) {
		int t, u, v, k;
		cin >> t >> u;
		if (t == 1) {
			cin >> v >> k;
			update_path(u, v, k);
		} else if (t == 3) {
			cin >> k;
			update_tree(u, k);
		} else if (t == 2) {
			cin >> v;
			cout << query_path(u, v) << '\n';
		} else {
			cout << query_tree(u) << '\n';
		}
	}

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
