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
void solve(int T) {
	//欧拉路径，必定存在
	double a, b, c, d, sum = 0;
	cin >> a >> b;
	while (cin >> a >> b >> c >> d) {
		double dx = a - c, dy = b - d;
		sum += sqrt(dx * dx + dy * dy) * 2;
	}
	int m = round(sum / 1000 / 20 * 60);
	int h = m / 60;
	m %= 60;
	printf("%d:%02d\n", h, m);
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
