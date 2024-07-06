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
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
struct DSU {
	int n, cnt;
	vector<int> p, siz;
	DSU(int n) : n(n), cnt(n), p(n + 1), siz(n + 1, 1) {
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

		cnt--;
		siz[x] += siz[y];
		p[y] = x;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};

int n, k, res = 1e18;
vector<pair<double, PII>>eg;
map<int, PII>pos;
vector<double>as;

double dist(int u, int v) {
	auto [x1, y1] = pos[u];
	auto [x2, y2] = pos[v];
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void solve() {
	cin >> n >> k;
	DSU d(n);

	for (int x = 1; x <= n; x++) {
		int u, v; cin >> u >> v;
		pos[x] = {u, v};
	}

	for (int x = 1; x <= n; x++)
		for (int y = x + 1; y <= n; y++) {
			eg.push_back({dist(x, y), {x, y}});
		}

	sort(all(eg));

	for (auto [w, pi] : eg) {
		auto [x, y] = pi;
		//de(w),de(x),deg(y);
		if (d.same(x, y))continue;
		as.push_back(w);
		d.merge(x, y);
	}

	sort(all(as), greater<int>());

	if (as.size() + 1 <= k) {
		cout << "0.00" << '\n';
		return;
	}
	cout << fixed << setprecision(2) << as[max(k - 1ll, 0ll)] << '\n';
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
