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

int n, m, k, len, w[N], ans[N];
struct Query {
	int id, l, r, res;
} q[N];
struct Range {
	int id, l, r, t;
};
vector<Range>range[N];
int f[N], g[N];

int get_count(int u) {
	int res = 0;
	while (u)res += u & 1, u >>= 1;
	return res;
}

int get(int u) {return u / len;}

bool cmp(const Query&a, const Query&b) {
	int i = get(a.l), j = get(b.l);
	if (i != j)return i < j;
	return a.r < b.r;
}

void solve() {
	cin >> n >> m >> k;

	for (int x = 1; x <= n; x++)cin >> w[x];
	vector<int>nums;

	for (int x = 0; x < 1 << 14; x++) {
		if (get_count(x) == k)
			nums.emplace_back(x);
	}
	for (int x = 1; x <= n; x++) {
		for (auto y : nums)++g[w[x]^y];

		f[x] = g[w[x + 1]];
	}

	for (int x = 0; x < m; x++) {
		int l, r; cin >> l >> r;

		q[x] = {x, l, r};
	}

	len = sqrt(n);
	sort(q, q + m, cmp);

	for (int x = 0, L = 1, R = 0; x < m; x++) {
		auto &[id, l, r, res] = q[x];

		if (R < r)range[L - 1].push_back({x, R + 1, r, -1});
		while (R < r)res += f[R++];
		if (R > r)range[L - 1].push_back({x, r + 1, R, 1});
		while (R > r)res -= f[--R];
		if (L < l)range[R].push_back({x, L, l - 1, -1});
		while (L < l)res += f[L - 1] + !k, L++;
		if (L > l)range[R].push_back({x, l, L - 1, 1});
		while (L > l)res -= f[L - 2] + !k, L--;
	}

	memset(g, 0, sizeof g);

	for (int x = 1; x <= n; x++) {
		for (auto y : nums)++g[w[x]^y];

		for (auto [id, l, r, t] : range[x])
			for (int y = l; y <= r; y++)
				q[id].res += g[w[y]] * t;
	}

	for (int x = 1; x < m; x++)q[x].res += q[x - 1].res;
	for (int x = 0; x < m; x++)ans[q[x].id] = q[x].res;
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
