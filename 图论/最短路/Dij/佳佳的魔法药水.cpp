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
int n, m, cost[N];
vector<vector<PII>>eg(N);
void dij() {
	vector<int>vis(n + 1, false), dist(n + 1), cnt(n + 1, 1);
	priority_queue<PII, vector<PII>, greater<PII>>que;
	for (int x = 1; x <= n; x++) {
		dist[x] = cost[x];
		que.push({cost[x], x});
	}

	while (que.size()) {
		auto [dis, t] = que.top(); que.pop();
		if (vis[t])continue;
		vis[t] = true;

		for (auto [it, id] : eg[t]) {
			if (!vis[id])continue;
			if (dist[it] > dist[t] + dist[id]) {
				dist[it] = dist[t] + dist[id];
				cnt[it] = cnt[t] * cnt[id];
				que.push({dist[it], it});
			} else if (dist[it] == dist[t] + dist[id]) {
				cnt[it] += cnt[t] * cnt[id];
			}
		}
	}
	cout << dist[1] << ' ' << cnt[1] << '\n';
}
void solve(int T) {
	cin >> n;
	for (int x = 1; x <= n; x++)cin >> cost[x];
	int a, b, c;
	while (cin >> a >> b >> c) {
		a++, b++, c++;
		eg[a].emplace_back(c, b);
		if (a == b)continue;//防止a b相等重复存路
		eg[b].emplace_back(c, a);
	}
	dij();
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