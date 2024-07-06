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
int n;
struct node {
	int lm, rm, sum, mx;
	void update(const node&x, const node&y) {
		lm = max(x.lm, x.sum + y.lm);
		rm = max(y.rm, y.sum + x.rm);
		sum = x.sum + y.sum;
		mx = max({x.mx, y.mx, x.rm + y.lm});
	}
};
vector<node>f[(1 << 18 ) * 18];

void build(int u, int l, int r, int k) {
	f[u].resize(r - l + 1);

	if (l == r) {
		int x; cin >> x;
		f[u][0] = {x, x, x, max(x, 0ll)};
		return;
	}

	int mid = (l + r) >> 1;
	build(u << 1, l, mid, k - 1);
	build(u << 1 | 1, mid + 1, r, k - 1);

	for (int x = 0; x < r - l + 1; x++) {
		if (x >> k & 1)f[u][x].update(f[u << 1 | 1][x ^ 1 << k], f[u << 1][x ^ 1 << k]);
		else f[u][x].update(f[u << 1][x], f[u << 1 | 1][x]);
	}

}
void solve() {
	cin >> n;

	build(1, 1, 1 << n, n - 1);

	int q, now = 0; cin >> q;

	while (q--) {
		int op; cin >> op;
		now ^= 1 << op;
		cout << f[1][now].mx << '\n';
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
