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
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

constexpr LL mod = 1e9 + 7; //mod
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


const int N = 1e6 + 10;
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


void solve() {
	int n, m; cin >> n >> m;

	int Siz[n + 1];
	memset(Siz, 0, sizeof Siz);
	int mp[n + 1];
	memset(mp, 0, sizeof mp);
	while (m--) {
		int u, v; cin >> u >> v;

		Siz[u]++;
		Siz[v]++;
	}

	for (int x = 1; x <= n; x++) {
		int siz = Siz[x];

		for (int y = 2; y <= siz; y++) {
			mp[y] += C(siz, y).val();
		}
	}

	int ans = 0;

	for (int x = 2; x <= n - 1; x++)ans ^= mp[x] % mod;

	cout << ans << '\n';

}
signed main () {
	init();
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
