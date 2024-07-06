#include <bits/stdc++.h>
using namespace std;
#define LL long long


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


const int N = 1e7 + 10;
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


