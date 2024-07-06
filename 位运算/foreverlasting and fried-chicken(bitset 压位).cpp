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
const int  INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

constexpr LL mod = 1000000007;//mod
class modint {
	LL num;
public:
	modint(LL num = 0) : num(num % mod) {}

	LL val() const {
		return num;
	}

	modint pow(LL other) {
		modint res(1), temp = *this;
		while (other) {
			if (other & 1) res = res * temp;
			temp = temp * temp;
			other >>= 1;
		}
		return res;
	}

	constexpr LL norm(LL num) const {
		if (num < 0) num += mod;
		if (num >= mod) num -= mod;
		return num;
	}

	modint inv() { return pow(mod - 2); }
	modint operator+(modint other) { return modint(num + other.num); }
	modint operator-() { return { -num }; }
	modint operator-(modint other) { return modint(-other + *this); }
	modint operator*(modint other) { return modint(num * other.num); }
	modint operator/(modint other) { return *this * other.inv(); }
	modint &operator*=(modint other) { num = num * other.num % mod; return *this; }
	modint &operator+=(modint other) { num = norm(num + other.num); return *this; }
	modint &operator-=(modint other) { num = norm(num - other.num); return *this; }
	modint &operator/=(modint other) { return *this *= other.inv(); }
	friend istream& operator>>(istream& is, modint& other) { is >> other.num; other.num %= mod; return is; }
	friend ostream& operator<<(ostream& os, modint other) { other.num = (other.num + mod) % mod; return os << other.num; }
};

const int N = 1e3 + 10;
modint fc[N], ifc[N];
void init() {
	int n = N - 5;
	fc[0] = 1;
	for (int i = 1; i <= n; i++) fc[i] = fc[i - 1] * i;
	ifc[n] = modint(1) / fc[n];
	for (int i = n - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1);
}

modint C(int n, int m) {
	if (n < m) return 0;
	if (m == 0) return 1;
	return fc[n] * ifc[n - m] * ifc[m];
}


int eg[1100][1100], n, m;
void solve() {
	cin >> n >> m;
	vector<vector<int>>_eg(n + 1);
	bitset<1100>fr[n + 1];
	for (int x = 1; x <= n; x++) {
		for (int y = x + 1; y <= n; y++)eg[x][y] = eg[y][x] = 0;
	}

	while (m--) {
		int u, v; cin >> u >> v;

		eg[u][v] = eg[v][u] = 1;
		fr[u][v] = 1; fr[v][u] = 1;
		_eg[u].emplace_back(v);
		_eg[v].emplace_back(u);
	}
	modint ans = modint(0);

	for (int x = 1; x <= n - 1; x++) {
		for (int y = x + 1; y <= n; y++) {

			int ct = ((fr[x] & fr[y]).count());

			int wx = _eg[x].size() - 4, wy = _eg[y].size() - 4;
			if (eg[x][y])wx--, wy--;

			ans += C(ct, 4) * (C(wx, 2) + C(wy, 2));
		}
	}

	cout << ans << '\n';
}
signed main () {
	/*freopen("C:\\Users\\MILI\\Desktop\\1.in", "r", stdin);
	freopen("1.out", "w", stdout);*/
	init();
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}