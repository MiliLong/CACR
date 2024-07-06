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
using ll = long long;
const int N = 2e5 + 10, INF = 1e18;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int n, k, idx = 0;; cin >> n >> k;

	vector<vector<int>>son(40 * n, vector<int>(2, 0));
	vector<int>a(n + 1), cnt(40 * n, 0);

	auto insert = [&](int h, int nn)->void{
		int p = 0;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			if (!son[p][u])son[p][u] = ++idx;
			p = son[p][u];
		}
		cnt[p] = nn;
	};

	auto query = [&](int h)->PII{
		int p = 0, res = 0;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			if (son[p][u]) {p = son[p][u]; res *= 2;}
			else {p = son[p][!u]; res = res * 2 + 1;}
		}
		return {res, cnt[p]};
	};

	int ans = INF; int i, j;
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		if (x >= 2) {
			auto [t, pos] = query(a[x]);

			if (t < ans) {
				ans = t;
				i = x; j = pos;
			}
		}
		insert(a[x], x);
	}
	if (i > j)swap(i, j);

	int as = 0;
	for (int x = k - 1; x >= 0; x--) {
		if ((a[i] >> x & 1) == (a[j] >> x & 1))as += (!(a[i] >> x & 1)) << x;
	}

	cout << i << ' ' << j << ' ' << as << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
