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
#define yes "Yes\n"
#define no "No\n";
using ll = long long;
const int N = 2e7 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
char a[N], b[N];
int p[N], n;
map<char, char>mp;
void pd() {
	for (int i = 0; i < 256; i++) mp[i] = 0;
	mp['o'] = 'o';
	mp['s'] = 's';
	mp['x'] = 'x';
	mp['z'] = 'z';
	mp['b'] = 'q';
	mp['q'] = 'b';
	mp['d'] = 'p';
	mp['p'] = 'd';
	mp['n'] = 'u';
	mp['u'] = 'n';
	mp['#'] = '#';
}
void init() {
	int k = 0;
	b[k++] = '$', b[k++] = '#';
	for (int x = 0; x < n; x++)b[k++] = a[x], b[k++] = '#';
	b[k++] = '^';
	n = k;
}
string manacher() {
	int mr = 0, md, start = 1;
	for (int x = 1; x < n; x++) {
		if (x < mr)p[x] = min(p[2 * md - x], mr - x);
		else p[x] = 0;

		while (b[x - p[x]] == mp[b[x + p[x]]])p[x]++;

		if (x + p[x] > mr) {
			mr = x + p[x];
			md = x;
		}

		if (p[x] > 0 && x - (p[x] - 1) == start) {
			b[x + p[x] - 1] = '$';
			start = x + p[x];
			x = x + p[x] - 1;
		}
	}
	if (start == n - 1)return yes;
	else return no;
}
void solve() {
	cin >> a;
	n = strlen(a);

	init();

	cout << manacher();

}
signed main () {
	pd();
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
