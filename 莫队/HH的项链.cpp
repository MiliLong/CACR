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

int n, m, len, cnt[N], w[N], ans[N];
struct Query {
	int id, l, r;
} q[N];

int get(int u) {return u / len;}

void motify(int u, int t, int &res) {
	cnt[u] += t;
	if (cnt[u] == 1 && t == 1)res++;
	if (cnt[u] == 0)res--;
}
void solve() {
	cin >> n;
	for (int x = 1; x <= n; x++)cin >> w[x];

	cin >> m;
	for (int x = 0; x < m; x++) {
		auto &[id, l, r] = q[x];
		cin >> l >> r;
		id = x;
	}

	len = sqrt(n);
	sort(q, q + m, [&](Query a, Query b) {
		int i = get(a.l), j = get(b.l);
		if (i != j)return i < j;
		return a.r < b.r;
	});

	for (int x = 0, L = 1, R = 0, res = 0; x < m; x++) {
		auto [id, l, r] = q[x];

		while (L > l)motify(w[--L], 1, res);
		while (R < r)motify(w[++R], 1, res);
		while (L < l)motify(w[L++], -1, res);
		while (R > r)motify(w[R--], -1, res);

		ans[id] = res;
	}

	for (int x = 0; x < m; x++)cout << ans[x] << '\n';
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
