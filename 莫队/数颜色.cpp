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
const int N = 1e4 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, w[N], len, cnt[1000010], ans[N], mq, mc;
struct Query {
	int id, l, r, t;
} q[N];
struct Modify {
	int  p, c;
} c[N];

int get(int u) {return u / len;}

void add(int u, int &res) {
	if (!cnt[u])res++;
	cnt[u]++;
}

void del(int u, int &res) {
	cnt[u]--;
	if (!cnt[u])res--;
}

void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> w[x];
	for (int x = 0; x < m; x++) {
		char op; int a, b; cin >> op >> a >> b;
		if (op == 'Q')mq++, q[mq] = {mq, a, b, mc};
		else c[++mc] = {a, b};

	}

	len = cbrt(n) + 1;
	sort(q + 1, q + 1 + mq, [&](Query a, Query b) {
		int al = get(a.l), ar = get(a.r), bl = get(b.l), br = get(b.r);
		if (al != bl)return al < bl;
		if (ar != br)return ar < br;
		return a.t < b.t;
	});

	for (int x = 1, L = 1, R = 0, T = 0, res = 0; x <= mq; x++) {
		auto [id, l, r, t] = q[x];

		while (L < l)del(w[L++], res);
		while (L > l)add(w[--L], res);
		while (R < r)add(w[++R], res);
		while (R > r)del(w[R--], res);
		while (T < t) {
			T++;
			if (c[T].p >= L && c[T].p <= R) {
				del(w[c[T].p], res);
				add(c[T].c, res);
			}
			swap(w[c[T].p], c[T].c);
		}
		while (T > t) {
			if (c[T].p >= L && c[T].p <= R) {
				del(w[c[T].p], res);
				add(c[T].c, res);
			}
			swap(w[c[T].p], c[T].c);
			T--;
		}

		ans[id] = res;
	}

	for (int x = 1; x <= mq; x++)cout << ans[x] << '\n';

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
