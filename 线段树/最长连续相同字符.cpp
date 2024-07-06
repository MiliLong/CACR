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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m;
char w[N];
struct Node {
	int l, r;
	int sum;
	int tmax, posl, posr;
	int lmax, psr;
	int rmax, psl;
} tr[N * 4];
void pushup(Node &u, Node &l, Node &r) {
	u.sum = l.sum + r.sum;
	if (l.lmax < l.sum) {
		u.lmax = l.lmax;
		u.psr = l.psr;
	}
	else {
		if (w[l.psr] == w[r.psr]) {
			u.lmax = l.sum + r.lmax;
			u.psr = r.psr;
		}
		else {
			u.lmax = l.lmax;
			u.psr = l.psr;
		}
	}

	if (r.rmax < r.sum) {
		u.rmax = r.rmax;
		u.psl = r.psl;
	}
	else {
		if (w[r.psl] == w[l.psl]) {
			u.rmax = r.sum + l.rmax;
			u.psl = l.psl;
		}
		else {
			u.rmax = r.rmax;
			u.psl = r.psl;
		}
	}

	if (w[l.psl] == w[r.psr]) {
		if (l.tmax >= l.rmax + r.lmax && l.tmax >= r.tmax) {
			u.tmax = l.tmax;
			u.posl = l.posl;
			u.posr = l.posr;
		}
		else if (r.tmax > l.rmax + r.lmax && r.tmax > l.tmax) {
			u.tmax = r.tmax;
			u.posl = r.posl;
			u.posr = r.posr;
		}
		else {
			u.tmax = l.rmax + r.lmax;
			u.posl = l.psl;
			u.posr = r.psr;
		}

	}
	else {
		if (l.tmax >= r.tmax) {
			u.tmax = l.tmax;
			u.posl = l.posl;
			u.posr = l.posr;
		}
		else {
			u.tmax = r.tmax;
			u.posl = r.posl;
			u.posr = r.posr;
		}
	}
}

void pushup(int u) {pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);}

void build(int u, int l, int r) {
	if (l == r)tr[u] = {l, r, 1, 1, l, r, 1, r, 1, l};
	else {
		tr[u] = {l, r};
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int x, char c) {
	int l = tr[u].l, r = tr[u].r;
	if (l == r && l == x) {
		tr[u] = {l, r, 1, 1, l, r, 1, r, 1, l};
		w[l] = c;
	}
	else {
		int mid = (l + r) >> 1;
		if (x <= mid)modify(u << 1, x, c);
		else modify(u << 1 | 1, x, c);
		pushup(u);
	}
}

Node query(int u, int l, int r) {
	int L = tr[u].l, R = tr[u].r;
	if (L >= l && R <= r)return tr[u];
	else {
		int mid = (L + R) >> 1;
		if (r <= mid)return query(u << 1, l, r);
		else if (l > mid)return query(u << 1 | 1, l, r);
		else {
			Node res;
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			pushup(res, left, right);
			return res;
		}
	}
}

void solve() {
	cin >> n >> m >> w + 1;

	build(1, 1, n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r; cin >> l >> r;
			auto res = query(1, l, r);
			cout << res.posl << ' ' << res.posr << '\n';
		}
		else {
			int a; char b; cin >> a >> b;
			modify(1, a, b);
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
