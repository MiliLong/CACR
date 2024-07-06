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
int n, m;
vector<vector<PII>>eg;
int dij() {
	vector<int>dist1(n + 1, INF), dist2(n + 1, INF);
	vector<vector<int>>vis(n + 1, vector<int>(2, false));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>que;
	dist1[1] = 0;
	que.push({0, 1, 0});

	while (que.size()) {
		auto [dis, t, vir] = que.top(); que.pop();
		if (vis[t][vir])continue;
		vis[t][vir] = true;

		for (auto [it, w] : eg[t]) {

			if (dist1[it] > dist1[t] + w) {
				dist2[it] = dist1[it];
				dist1[it] = dist1[t] + w;
				que.push({dist1[it], it, 0});
				que.push({dist2[it], it, 1});
			}
			else if (dist1[it] < dist1[t] + w && dist2[it] > dist1[t] + w) {
				dist2[it] = dist1[t] + w;
				que.push({dist2[it], it, 1});
			} else if (dist2[it] > dist2[t] + w) {
				dist2[it] = dist2[t] + w;
				que.push({dist2[it], it, 1});
			}
		}
	}
	return dist2[n];
}
void solve(int T) {
	cin >> n >> m;
	eg.resize(n + 1);
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		eg[u].emplace_back(v, w);
		eg[v].emplace_back(u, w);
	}

	cout << dij() << '\n';
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
