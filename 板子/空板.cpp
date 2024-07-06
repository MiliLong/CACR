#include<bits/stdc++.h>
// #pragma GCC optimize (1)
// #pragma GCC optimize (2)
// #pragma GCC optimize (3)
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define _len(a) (a.end()-a.begin())
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define _while(a) for(int _=0;_<a;_++)
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long
#define yes "YES\n"
#define no "NO\n"
using LL = long long;
using namespace std;

constexpr int N = 2e5 + 10, INF = 1e17;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

constexpr LL mod = 1e9 + 7;
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

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> tr;
    Fenwick(int n) : n(n), tr(n + 1) {}

    inline lowbit(int x) { return x & -x; }

    void add(int i, T val) {
        for (; i <= n; i += lowbit(i)) {
            tr[i] += val;
        }
    }

    T sum(T i) {
        T res = 0;
        for (; i > 0; i -= lowbit(i)) {
            res += tr[i];
        }
        return res;
    }

    T query(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    T kth(int k) {
        int x = 0;
        T res = 0;
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && k >= tr[x + i]) {
                x += i;
                k -= tr[x];
                res += tr[x];
            }
        }
        return (k ? -1 : res);
    }
};

void solve() {

}

signed main () {
    // init();
    ios::sync_with_stdio(0), cin.tie(0);
    int TT = 1;
    cin >> TT, cin.get();
    while (TT--) {
        solve();
    }
    return 0;
}
