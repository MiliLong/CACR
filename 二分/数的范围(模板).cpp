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

/*int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
*/

/*int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
*/
void solve() {
	int n, q; cin >> n >> q;
	int a[n + 1];

	for (int x = 0; x < n; x++)cin >> a[x];

	while (q--) {
		int p; cin >> p;

		int l = 0, r = n - 1;

		while (l < r) {
			int md = (l + r) >> 1;
			if (a[md] >= p)r = md;
			else l = md + 1;
		}

		if (a[l] == p)cout << l << ' ';
		else cout << -1 << ' ';

		l = 0, r = n - 1;

		while (l < r) {
			int md = (l + r + 1) >> 1;
			if (a[md] <= p)l = md;
			else r = md - 1;
		}

		if (a[l] == p)cout << l << '\n';
		else cout << -1 << '\n';
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
