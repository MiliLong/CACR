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
const int N = 2e7 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
char a[N], b[N];
int p[N], n;
void init() {
	int k = 0;
	b[k++] = '$', b[k++] = '#';
	for (int x = 0; x < n; x++)b[k++] = a[x], b[k++] = '#';
	b[k++] = '^';
	n = k;
}
void manacher() {
	int mr = 0, md;
	for (int x = 1; x < n; x++) {
		if (x < mr)p[x] = min(p[2 * md - x], mr - x);
		else p[x] = 1;

		while (b[x - p[x]] == b[x + p[x]])p[x]++;

		if (x + p[x] > mr) {
			mr = x + p[x];
			md = x;
		}
	}
}
void solve() {
	cin >> a;
	n = strlen(a);

	init();
	manacher();

	int res = 0;
	for (int x = 0; x < n; x++)res = max(res, p[x]);

	cout << res - 1 << '\n';

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
