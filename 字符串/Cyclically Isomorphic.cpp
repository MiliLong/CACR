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
void solve() {
	int n, m; cin >> n >> m;

	vector<vector<vector<int>>>a(n + 1, vector<vector<int>>(26, vector<int>(26, 0)));
	for (int x = 1; x <= n; x++) {
		string s; cin >> s;

		for (int y = 0; y < m - 1; y++) {
			a[x][s[y] - 'a'][s[y + 1] - 'a']++;
		}
		a[x][s[m - 1 ] - 'a'][s[0] - 'a']++;
	}

	int k; cin >> k;
	while (k--) {
		int i, j; cin >> i >> j;
		if (a[i] == a[j])cout << "Yes\n";
		else cout << "No\n";
	}

}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}

