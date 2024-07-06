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
//#define int long long
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
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

void solve() {

    int n, m, res = 0; cin >> n >> m;
    DSU d(n);
    vector<array<int, 3>>eg(m);

    for (auto &[w, u, v] : eg) {
        cin >> u >> v >> w;
    }

    sort(all(eg));

    for (auto &[w, u, v] : eg) {
        if (d.find(u) == d.find(v))continue;
        res += w;
        d.merge(u, v);
    }

    if (d.cnt == 1)cout << res << '\n';
    else cout << "impossible\n";
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
