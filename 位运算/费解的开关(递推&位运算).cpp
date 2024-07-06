#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
int dx[5] = { -1, 0, 1, 0, 0}, dy[5] = {0, -1, 0, 1, 0}, g[6][6], back[6][6];
void turn(int a, int b) {
	for (int x = 0; x < 5; x++) {
		int na = a + dx[x], nb = b + dy[x];
		if (na < 5 && na >= 0 && nb < 5 && nb >= 0) {
			g[na][nb] ^= 1; //按位取反
		}
	}
}//操作改变自身及其周围状态
void solve() {
	int ans = 10;
	for (int x = 0; x < 5; x++)for (int y = 0; y < 5; y++) {
			char i;
			cin >> i;
			g[x][y] = i - '0';
		}
	for (int op = 0; op < 32; op++) {
		//第一行的所有可能操作2的5次方，化为二进制表示
		memcpy(back, g, sizeof g); //备份
		int step = 0;
		for (int i = 0; i < 5; i++) {
			if ((op >> i) & 1) {
				//找到该位置状态并判断0位是否为1
				step++;
				turn(0, i);
			}
		}
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 5; y++) {
				if (g[x][y] == 0) {
					step++;
					turn(x + 1, y);
				}
			}
		}
		bool ok = true;
		for (int x = 0; x < 5; x++) {
			if (g[4][x] == 0) {
				ok = false;
				break;
			}
		}
		if (ok)ans = min(ans, step);
		memcpy(g, back, sizeof back);
	}
	if (ans > 6)ans = -1;
	cout << ans << endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
