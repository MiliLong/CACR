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
int son[N][26], cnt[N], idx;
void solve() {
	int n; cin >> n;

	auto insert = [&](string s)->void{
		int p = 0;
		for (auto it : s) {
			int u = it - 'a';
			if (!son[p][u])son[p][u] = ++idx;
			p = son[p][u];
		}

		cnt[p]++;
	};

	auto query = [&](string s)->int{
		int p = 0;
		for (auto it : s) {
			int u = it - 'a';
			if (!son[p][u])return 0;
			p = son[p][u];
		}

		return cnt[p];
	};

	while (n--) {
		char op; cin >> op;
		string st; cin >> st;
		if (op == 'I')insert(st);
		else if (op == 'Q')cout << query(st) << '\n';
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
