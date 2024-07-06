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
#define int long long
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int son[31 * N][2], cnt[31 * N], idx = 1;
void solve() {
	int n, hp; cin >> n >> hp;

	auto insert = [&](int h, int d )->void{
		int p = 1;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			if (!son[p][u])son[p][u] = ++idx;
			p = son[p][u];
			cnt[p] += d;
		}
	};

	auto query = [&](int h, int hh)->int{
		int p = 1, res = 0;
		for (int x = 30; x >= 0; x--) {
			int u = (h >> x) & 1;
			int v = (hh >> x) & 1;
			if (v == 1) {p = son[p][!u];}
			else {res += cnt[son[p][!u]]; p = son[p][u];}
		}
		return res;
	};

	while (n--) {
		char op; int x, ht; cin >> op >> x;
		if (op == '2')cin >> ht;

		if (op == '0')insert(x, 1);
		else if (op == '1')insert(x, -1);
		else if (op == '2') {
			int t = query(x, ht);
			if (!t)hp--;
			cout << t << '\n';
		}
	}

	cout << hp << '\n';
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
