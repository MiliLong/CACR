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

constexpr LL mod = 998244353;//mod
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
void solve() {
	int n, s; cin >> n >> s;
	vector<array<int, 3>>eg(n - 1);
	DSU d(n);
	for (int x = 0; x < n - 1; x++) {
		int w, a, b; cin >> a >> b >> w;
		eg[x] = {w, a, b};
	}
	sort(all(eg));
	modint res = 1;
	for (auto [w, u, v] : eg) {
		int t = d.size(u) * d.size(v) - 1;
		res *= modint(s - w + 1).pow(t);

		d.merge(u, v);
	}

	cout << res << '\n';

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
