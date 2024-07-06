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
const int N = 2e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, e[N], ne[N], h[N], idx, tp[N], q[N], d[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort() {
	int hh = 0, tt = -1;
	for (int x = 1; x <= n; x++) {
		if (!d[x]) {q[++tt] = x;}
	}

	while (hh <= tt) {
		int t = q[hh++];

		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];

			if (--d[j] == 0) {q[++tt] = j;}
		}
	}
	return tt == n - 1;
}
void solve() {
	cin >> n >> m;

	memset(h, -1, sizeof h);
	while (m--) {
		int u, v; cin >> u >> v;

		add(u, v);
		d[v]++;
	}

	if (topsort()) {
		cout << 1 << '\n';

		for (int x = 0; x < n; x++) {if (x)cout << ' '; cout << q[x];}
		cout << '\n';
	}
	else {
		cout << 2 << '\n';

		for (int x = 0; x < n; x++) {if (x)cout << ' '; cout << x + 1;}
		cout << '\n';
		for (int x = 0; x < n; x++) {if (x)cout << ' '; cout << n - x;}
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
