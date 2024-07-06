#include<bits/stdc++.h>
#include<bitset>
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
void solve() {
	int a, b; int ans = 0;
	cout << '?';
	for (int x = 1; x <= 100; x++)cout << ' ' << x;
	cout << endl;
	cin >> a;
	cout << '?';
	for (int x = 1; x <= 100; x++)cout << ' ' << (x << 7);
	cout << endl;
	cin >> b;
	int c = 0;
	for (int x = 0; x <= 6; x++)c += (1 << x);
	cout << "! " << ((b & c) | ((a >> 7) << 7)) << endl;
	/*cout << bitset<14>(a) << ' ' << bitset<14>(b) << '\n';
	cout << bitset<14>(((a >> 7) << 7)) << ' ' << bitset<14>((b & c)) << '\n';
	cout << bitset<14>(((b & c) | ((a >> 7) << 7))) << '\n';*/
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
