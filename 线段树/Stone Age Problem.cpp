#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long
using ll = long long;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
using namespace std;
int n, m, w[N];
struct Node {
	int l, r;
	int sum, add; //add：：懒标记
} tr[4 * N];
void pushup(int u) {
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u) {
	auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
	if (root.add) {
		left.add = root.add, left.sum = root.add * (left.r - left.l + 1);
		right.add = root.add, right.sum = root.add * (right.r - right.l + 1);
		root.add = 0;
	}
}
void build(int u, int l, int r) {
	if (l == r)tr[u] = {l, r, w[r], 0};
	else {
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, int d) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].sum = d * (tr[u].r - tr[u].l + 1);
		tr[u].add = d;
	}
	else {
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if (l <= mid)modify(u << 1, l, r, d);
		if (r > mid)modify(u << 1 | 1, l, r, d);
		pushup(u);
	}
}
int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r)return tr[u].sum;
	else {
		pushdown(u);
		int sum = 0;
		int mid = tr[u].l + tr[u].r >> 1;
		if (l <= mid)sum += query(u << 1, l, r);
		if (r > mid)sum += query(u << 1 | 1, l, r);
		return sum;
	}
}
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> w[x];
	build(1, 1, n);
	int op;
	while (m--) {
		cin >> op;
		if (op == 1) {
			int x, y; cin >> x >> y;
			modify(1, x, x, y);
		}
		else if (op == 2) {
			int x; cin >> x;
			modify(1, 1, n, x);
		}
		cout << query(1, 1, n) << '\n';
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
