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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, l, r;
int f[N];
int sg(int u) {
	if (f[u] != -1)return f[u];
	set<int>st;
	for (int x = l; x <= r; x++) {
		if (u >= x)st.insert(sg(u - x));
	}
	int res = 0;
	while (st.count(res))res++;
	return f[u] = res;
}
void solve(int T) {
	memset(f, -1, sizeof f);
	cin >> n >> l >> r;
	for (int x = 0; x < l; x++)f[x] = 0;
	int res = 0;
	for (int x = 0, i; x < n; x++) {
		cin >> i;
		res ^= sg(i);
	}
	cout << (res ? 'C' : 'Y') << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
