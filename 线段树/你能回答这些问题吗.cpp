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
const int N = 5e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, w[N];
struct Node {
	int l, r;
	int lmax, rmax, tmax, sum;
} tree[N * 4];

void pushup(Node &u, Node &l, Node &r) {
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, r.lmax + l.sum);
	u.rmax = max(r.rmax, l.rmax + r.sum);
	u.tmax = max({l.tmax, r.tmax, l.rmax + r.lmax});
}

void pushup(int u) {
	pushup(tree[u], tree[u << 1], tree[u << 1 | 1]);
}

void build(int u, int l, int r) {
	if (l == r)tree[u] = {l, r, w[l], w[l], w[l], w[l]};
	else {
		tree[u] = {l, r};
		int mid = (l + r) >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int x, int y) {
	if (tree[u].l == x && tree[u].r == x)tree[u] = {x, x, y, y, y, y};
	else {
		int mid = (tree[u].l + tree[u].r) >> 1;
		if (x <= mid)modify(u << 1, x, y);
		else modify(u << 1 | 1, x, y);
		pushup(u);
	}
}

Node query(int u, int l, int r) {
	if (tree[u].l >= l && tree[u].r <= r)return tree[u];
	else {
		int mid = (tree[u].l + tree[u].r) >> 1;

		if (r <= mid)return query(u << 1, l, r);
		else if (l > mid)return query(u << 1 | 1, l, r);
		else {
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			Node res;
			pushup(res, left, right);
			return res;
		}
	}
}
void solve() {
	cin >> n >> m;

	for (int x = 1; x <= n; x++)cin >> w[x];

	build(1, 1, n);
	while (m--) {
		int k, x, y; cin >> k >> x >> y;

		if (k == 1) {
			if (x > y)swap(x, y);

			cout << query(1, x, y).tmax << '\n';
		}
		else {
			modify(1, x, y);
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
