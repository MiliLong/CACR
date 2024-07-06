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
using namespace std;
int tree[N + 2];
int n, m;
int lowbit(int x) {
    return x & (-x);
}
void add(int a, int b) {
    for (int x = a; x <= N; x += lowbit(x))tree[x] += b;
}
int sum(int a) {
    int res = 0;
    for (int x = a; x; x -= lowbit(x))res += tree[x];
    return res;
}
void solve() {
    cin >> n >> m;
    vector<int>a(n + 1), s(N, 0);
    for (int x = 1; x <= n; x++)cin >> a[x], s[a[x]]++;
    for (int x = 1; x <= N; x++)add(x, s[x]);
    while (m--) {
        int p, q; cin >> p >> q;
        s[a[p]]--; s[q]++;
        add(a[p], -1), add(q, 1);
        a[p] = q;
        int ans = 0;
        int l = 1, r = N;
        while (l <= r) {
            int md = (l + r) >> 1;
            if (sum(md) > n / 2) {
                ans = md;
                r = md - 1;
            }
            else l = md + 1;
        }
        cout << ans << '\n';
    }
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
