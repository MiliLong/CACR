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

int oula(int u) {
	int res = u;

	for (int i = 2; i <= u / i; i++) {
		if (u % i == 0) {
			res = res / i * (i - 1);
			while (u % i == 0)u /= i;
		}
	}
	if (u > 1)res = res / u * (u - 1);

	return res;
}
int qmi(int u, int k, int p) {
	int res = 1, t = u;
	while (k) {
		if (k & 1)res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res % p;
}
void solve() {
	int n, p; cin >> n >> p;
	int o = oula(p);
	cout << qmi(2, qmi(2, n, o) + o, p) << '\n';//本题该代码缺失部分特判+o操作,仅作为公式保存;
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
