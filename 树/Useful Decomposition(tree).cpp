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
	int n; cin >> n;
	vector<vector<int>>eg(n + 1);
	vector<int>a, ans;
	for (int x = 0; x < n - 1; x++) {
		int i, j; cin >> i >> j;

		eg[i].emplace_back(j);
		eg[j].emplace_back(i);
	}

	for (int x = 1; x <= n; x++) {
		if (eg[x].size() >= 3)a.emplace_back(x);
		else if (eg[x].size() == 1)ans.emplace_back(x);
	}

	if (a.size() >= 2) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	if (a.size()) {
		cout << ans.size() << '\n';
		for (auto it : ans) {
			cout << a[0] << ' ' << it << '\n';
		}
	}
	else cout << 1 << '\n' << ans[0] << ' ' << ans[1] << '\n';

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
