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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int son[31 * N][2], cnt[31 * N], idx;
void solve() {
	cout << __lg(1000000000) ;
	int n; cin >> n;

	auto insert = [&](int h)->void{
		int p = 0;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			if (!son[p][u])son[p][u] = ++idx;
			p = son[p][u];
		}
	};

	auto query = [&](int h)->int{
		int p = 0, res = 0;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			if (son[p][!u]) {p = son[p][!u]; res = res * 2 + !u;}
			else {p = son[p][u]; res = res * 2 + u;}
		}
		return res;
	};

	int ans = 0;
	for (int x = 0; x < n; x++) {
		int i; cin >> i;
		insert(i);
		int t = query(i);
		ans = max(ans, i ^ t);
	}

	cout << ans << '\n';
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
