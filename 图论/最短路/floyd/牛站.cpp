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
const int N = 1e3 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int k, m, s, e, cnt, dist[N][N], res[N][N];
map<int, int>pos;

void mul(int c[][N], int a[][N], int b[][N]) {
	static int temp[N][N];
	memset(temp, 0x3f, sizeof temp);

	for (int k = 1; k <= cnt; k++)
		for (int x = 1; x <= cnt; x++)
			for (int y = 1; y <= cnt; y++)
				temp[x][y] = min(temp[x][y], a[x][k] + b[k][y]);

	memcpy(c, temp, sizeof temp);
}

void qmi() {
	memset(res, 0x3f, sizeof res);
	for (int x = 1; x <= cnt; x++)res[x][x] = 0;
	while (k) {
		if (k & 1)mul(res, res, dist);
		mul(dist, dist, dist);
		k >>= 1;
	}
}

void solve() {
	cin >> k >> m >> s >> e;

	memset(dist, 0x3f, sizeof dist);
	while (m--) {
		int c, a, b; cin >> c >> a >> b;

		if (pos.count(a) == 0)pos[a] = ++cnt;
		if (pos.count(b) == 0)pos[b] = ++cnt;
		a = pos[a], b = pos[b];
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}

	if (pos.count(s) == 0)pos[s] = ++cnt;
	if (pos.count(e) == 0)pos[e] = ++cnt;
	s = pos[s], e = pos[e];

	qmi();

	cout << res[s][e] << '\n';
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
