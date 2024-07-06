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
	int _min, add; //add：：懒标记
} tr[4 * N];
void pushup(int u) {
	tr[u]._min = min(tr[u << 1]._min, tr[u << 1 | 1]._min);
}
void pushdown(int u) {
	auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
	if (root.add) {
		left.add += root.add, left._min += root.add;
		right.add += root.add, right._min += root.add;
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
		tr[u]._min += d;
		tr[u].add += d;
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
	if (tr[u].l >= l && tr[u].r <= r)return tr[u]._min;
	else {
		pushdown(u);
		int _min = INF;
		int mid = tr[u].l + tr[u].r >> 1;
		if (l <= mid)_min = min(_min, query(u << 1, l, r));
		if (r > mid)_min = min(_min, query(u << 1 | 1, l, r));
		return _min;
	}
}
void solve() {
	cin >> n;
	for (int x = 1; x <= n; x++)cin >> w[x];

	build(1, 1, n);

	cin >> m;
	while (m--) {
		int l, r; cin >> l >> r; char c = '0';
		l++, r++;

		c = cin.get();
		if (c != '\n') {
			int g; cin >> g;
			if (l <= r)modify(1, l, r, g);
			else modify(1, l, n, g), modify(1, 1, r, g);
		}
		else {
			if (l <= r)cout << query(1, l, r) << '\n';
			else cout << min(query(1, l, n), query(1, 1, r)) << '\n';
		}
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
