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
using LL = long long;
const int N = 1e6 + 10, INF = 1e17;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int tree[N];
int lowbit(int x) {return x & (-x);}
void add(int a, int b) {
	for (int x = a; x <= N - 1; x += lowbit(x))tree[x] += b;
}
int ask(int a) {
	int res = 0;
	for (int x = a; x; x -= lowbit(x))res += tree[x];
	return res;
}
void solve() {
	int sz = 1, q;
	cin >> q;
	vector<vector<PII>>que(q + 2);
	vector<vector<int>>eg(q + 2);
	vector<int>ans(q + 2, 0);
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int a; cin >> a;
			eg[a].emplace_back(sz + 1);
			sz++;
		} else {
			int a, b; cin >> a >> b;
			que[a].emplace_back(sz, b);
		}
	}

	auto dfs = [&](auto && dfs, int u) -> void {
		for (auto [t, v] : que[u]) {
			add(t, v);
		}
		ans[u] = ask(sz) - ask(u - 1);
		for (auto it : eg[u]) {
			dfs(dfs, it);
		}

		for (auto [t, v] : que[u]) {
			add(t, -v);
		}
	};
	dfs(dfs, 1);
	for (int x = 1; x <= sz; x++)cout << ans[x] << " \n"[x == sz];
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int TT = 1;
	cin >> TT, cin.get();
	while (TT--) {
		solve();
	}
	return 0;
}
