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
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = "0" + s;
    s += "0";
    int ma = 0;
    vector<int>a(n + 2, 0), b(n + 2, 0);
    for (int x = 1; x <= n; x++) {
        if (s[x - 1] == '0' && s[x] == '1')a[x] = 1;
        else if (s[x - 1] == '1' && s[x] == '0')a[x] = 0;
        else if (s[x - 1] == '1' && s[x] == '1')a[x] = a[x - 1] + 1;
    }
    for (int x = 1; x <= n; x++)a[x] = max(a[x], a[x - 1]);
    for (int x = n; x >= 1; x--) {
        if (s[x + 1] == '0' && s[x] == '1')b[x] = 1;
        else if (s[x + 1] == '1' && s[x] == '0')b[x] = 0;
        else if (s[x + 1] == '1' && s[x] == '1')b[x] = b[x + 1] + 1;
    }
    for (int x = n; x >= 1; x--)b[x] = max(b[x], b[x + 1]);
    for (int x = 1; x <= n; x++) {
        ma = max(ma, a[x] + b[x + 1]);
    }
    cout << ma << '\n';
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
