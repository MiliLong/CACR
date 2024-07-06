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
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

struct DSU {
	int n;
	vector<int> p, siz;
	DSU(int n) : n(n), p(n + 1), siz(n + 1, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int find(int x) {
		if (x != p[x]) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		siz[x] += siz[y];
		p[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};

void solve2() {
	int n, m; cin >> n >> m;
	set<pair<int, PII>>st;
	for (int x = 0; x < n - 1; x++) {
		int i, j, w; cin >> i >> j >> w;
		st.insert({w, {i, j}});
	}
	int sum = 0;
	vector<int>ans(N + 1, 0);
	DSU a(n);
	for (auto [wt, pir] : st) {
		auto [x, y] = pir;
		if (!a.same(x, y)) {
			sum += a.size(x) * a.size(y);
			a.merge(x, y);
		}
		ans[wt] = sum;
	}
	for (int x = 1; x <= N; x++)ans[x] = max(ans[x], ans[x - 1]);
	while (m--) {
		int q; cin >> q;
		cout << ans[q];
		if (m != 0)cout << ' ';
	}
}

void solve1() {
	int n, m; cin >> n >> m;
	set<pair<int, PII>>st;
	for (int x = 0; x < n - 1; x++) {
		int i, j, w; cin >> i >> j >> w;
		st.insert({w, {i, j}});
	}

	vector<int>f(n + 1), s(n + 1, 1), ans(N + 1, 0);
	int sum = 0;
	for (int x = 1; x <= n; x++)f[x] = x;

	auto find = [&](auto && find, int u)->int{
		if (f[u] != u)return f[u] = find(find, f[u]);
		return u;
	};
	auto merge = [&](int i, int j)->void{
		int fi = find(find, i), fj = find(find, j);
		if (fi != fj) {
			f[fj] = fi;
			sum += s[fj] * s[fi];
			s[fi] += s[fj];
		}
	};
	for (auto [wt, pir] : st) {
		auto [x, y] = pir;
		merge(x, y);
		ans[wt] = sum;
	}
	for (int x = 1; x <= N; x++)ans[x] = max(ans[x], ans[x - 1]);
	while (m--) {
		int q; cin >> q;
		cout << ans[q];
		if (m != 0)cout << ' ';
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		//solve1();
		solve2();
	}
	return 0;
}
