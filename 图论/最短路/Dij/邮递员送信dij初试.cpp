#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n, m;
int g[1002][1002], g1[1002][1002], g2[1002][1002];//建立邻接矩阵，a>b!=b>a,即g[x][y],g[y][x]不同，为方向相反的两者。即该矩阵有向（太大爆内存）；
//由于去路和回路并不同所有需要一个正向图和逆向图，逆向图则是可化为1>n来dij，此处自行理解；
int dij() {
	int dist[n + 1];
	for (int x = 1; x <= n; x++) {
		dist[x] = g[1][x];
	}//最短距离初始化；有则正常，无则INF
	bool vis[n + 1];//判断是否最短；
	memset(vis, false, sizeof vis);
	//vis[1] = true;//可加可不加；
	for (int x = 1; x <= n; x++) { /*大部分时候用不了n次那么多就进行完了，相当于极限情况下用n次*/
		int t = -1;
		for (int z = 1; z <= n; z++) { /*显然未确定点最多除初始位置外n-1个但这显然不可能，应该更少个*/
			if (!vis[z]/*判断未确定*/ && (t == -1 /*第一步必定替换*/ || dist[t] > dist[z]/*之后满足该条件替换*/)) {
				t = z;
			}
		}//找最短路未确定的最近点；
		vis[t] = true;//找到了；
		for (int q = 1; q <= n; q++) {
			dist[q] = min(dist[q], dist[t] + g[t][q]);
		}//更新最短距离；
	}//可知for循环内操作是肯定溢出的，从而保证正确性；
	int as = 0;
	for (int x = 1; x <= n; x++)as += dist[x];
	return as;
}
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)for (int y = 1; y <= n; y++) {
			if (x == y)g1[x][y] = 0, g2[x][y] = 0;
			else {
				g1[x][y] = INF;
				g2[x][y] = INF;
			}
		}//邻接矩阵的初始化，INF，和赋0；
	for (int x = 1; x <= m; x++) {
		int a, b, c;
		cin >> a >> b >> c;
		g1[a][b] = min(c, g1[a][b]);
		g2[b][a] = min(c, g2[b][a]);
	}//正常的读入；
	for (int x = 1; x <= n; x++)for (int y = 1; y <= n; y++)g[x][y] = g1[x][y];
	int as1 = dij();
	for (int x = 1; x <= n; x++)for (int y = 1; y <= n; y++)g[x][y] = g2[x][y];
	int as2 = dij();
	cout << as1 + as2 << endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
