#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
//#define int long long
using ll = long long;
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
using namespace std;
//总结：：判断连通性的floyd标准做法
//g[x][y]=g[x][y]||(g[x][z]&&g[z][y])
int n;
bool g[N][N];
void floyd() {
	for (int z = 1; z <= n; z++)for (int x = 1; x <= n; x++)for (int y = 1; y <= n; y++) {
				g[x][y] = g[x][y] || (g[x][z] && g[z][y]);
			}
}
void solve() {
	cin >> n;
	memset(g, false, sizeof g);
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int c;
			cin >> c;
			if (c) {
				g[x][y] = true;
			}
		}
	}
	floyd();
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			if (g[x][y])cout << 1;
			else cout << 0;
			if (y != n)cout << ' ';
		}
		cout << endl;
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
