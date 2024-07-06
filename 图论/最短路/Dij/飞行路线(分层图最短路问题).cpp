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
using LL = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, m, k, st, ed;
vector<vector<PII>>eg(N);
int dij() {
	vector<int>vis(N, false), dist(N, INF);

	priority_queue<PII, vector<PII>, greater<PII>>que;
	que.push({0, st});
	dist[st] = 0;

	while (que.size()) {
		auto [dis, t] = que.top(); que.pop();
		if (vis[t])continue;
		vis[t] = true;
		for (auto [it, w] : eg[t]) {
			if (dist[it] > dis + w) {
				dist[it] = dis + w;
				que.push({dist[it], it});
			}
		}
	}
	int res = INF;
	for (int x = 0; x <= k; x++) {
		res = min(res, dist[ed + x * n]);
	}
	return res;
}
void solve(int T) {
	cin >> n >> m >> k;
	cin >> st >> ed;
	st++, ed++;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		u++, v++;
		eg[u].emplace_back(v, w);
		eg[v].emplace_back(u, w);
		for (int x = 1; x <= k; x++) {
			eg[u + (x - 1)*n].emplace_back(v + x * n, 0);
			eg[v + (x - 1)*n].emplace_back(u + x * n, 0);
			eg[u + x * n].emplace_back(v + x * n, w);
			eg[v + x * n].emplace_back(u + x * n, w);
		}
	}
	cout << dij() << '\n';
}
signed main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
