#include<bits/stdc++.h>
using namespace std;
bool a[1001][1001];
char i;
int dp[1001][1001], up[1001][1001], res = 0, mid;
void solve() {
	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++)for (int y = 0; y < m; y++) {
			dp[x][y] = 0, up[x][y] = 0;
			cin >> i;
			if (i == 'F')a[x][y] = true;
			else a[x][y] = false;
		}
	for (int x = 0; x < n; x++)for (int y = 0; y < m; y++) {
			if (a[x][y]) {
				for (int z = x; z >= 0; z--) {
					if (!a[z][y])break;
					else up[x][y]++;
				}
			}
		}
	for (int x = 0; x < n; x++)for (int y = 0; y < m; y++) {
			if (a[x][y]) {
				int right = y, left = y, pd = 0, pd1 = 0;
				for (; ;) {
					if (pd && pd1)break;
					if (left >= 1 && up[x][left - 1] >= up[x][y] && a[x][left - 1]) {
						left--;
					} else {
						pd = 1;
					}
					if (right <= m - 2 && up[x][right + 1] >= up[x][y] && a[x][right + 1]) {
						right++;
					} else {
						pd1 = 1;
					}
				}
				mid = right - left + 1;
				mid *= up[x][y];
				res = max(res, mid);
			}
		}
	cout << res * 3 << endl;
}
int main () {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
