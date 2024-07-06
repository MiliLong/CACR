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
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
void solve() {
	int n, m, k, ans = 0; cin >> n >> m >> k;
	vector<vector<int>>eg(n + 1);
	vector<int>dist(n + 1, 1000000000);

	while (m--) {
		int i, j; cin >> i >> j;
		eg[i].emplace_back(j);
		eg[j].emplace_back(i);
	}

	queue<int>que;
	dist[1] = 0;

	que.push(1);
	while (que.size()) {
		int t = que.front(); que.pop();

		if (dist[t] <= k)ans++;
		int son = eg[t].size() - 1;

		if (t != 1 && son == 0 && dist[t] < k)ans += k - dist[t];

		for (auto it : eg[t]) {
			if (dist[it] > dist[t] + 1) {
				dist[it] = dist[t] + 1;
				que.push(it);
			}
			else if (dist[it] == dist[t]) {if (dist[it] < k)ans += k - dist[it];}
			else if (dist[it] == dist[t] + 1) {if (dist[it] <= k)ans += 1 + 2 * (k - dist[it]);}
		}
	}

	cout << ans << '\n';
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
