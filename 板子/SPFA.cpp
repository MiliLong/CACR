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
#define yes "Yes\n"
#define no "No\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

class Spfa {
public:
	int n, _INF = 1e9;
	vector<vector<PII>>eg;
	vector<int>dist, vis;

	void spfa(int st) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);

		dist[st] = 0; vis[st] = 1;
		deque<int>que;

		que.push_front(st);
		while (que.size()) {
			auto vir = que.front(); que.pop_front();
			vis[vir] = 0;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] > dist[vir] + w) {
					dist[it] = dist[vir] + w;

					if (vis[it])continue;
					vis[it] = 1;

					if (!que.empty() && dist[it] < dist[que.front()])que.push_front(it);
					else que.push_back(it);
				}
			}
		}
	}

	void add(int a, int b, int w) {
		eg[a].push_back({b, w});
	}
	
	Spfa(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1) {};

};

void solve() {


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
