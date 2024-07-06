#include<bits/stdc++.h>
//#pragma GCC optimize (1)
#pragma GCC optimize (2)
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

class SPFA {
public:
	int n;
	vector<int>cnt, vis, dist, w, tm;
	void add(int a, int b, int w, vector<vector<PII>>& eg) {
		eg[a].push_back({b, w});
	}

	void build(int u, vector<vector<PII>>& eg) {
		for (int x = 1; x <= 24; x++) {
			add(x - 1, x, 0, eg);
			add(x, x - 1, -tm[x], eg);
		}
		for (int x = 8; x <= 24; x++) {
			add(x - 8, x, w[x], eg);
		}
		for (int x = 1; x <= 7; x++) {
			add(x + 16, x, -u + w[x], eg);
		}
		add(0, 24, u, eg), add(24, 0, -u, eg);
	}

	bool spfa(int st) {
		vector<vector<PII>>eg(n + 1);
		build(st, eg);
		dist.insert(dist.begin(), n + 1, -INF);
		cnt.insert(cnt.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, false);
		queue<int>que;
		dist[0] = 0;
		vis[0] = true;
		que.push(0);
		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = false;

			for (auto [it, w] : eg[t]) {
				if (dist[it] < dist[t] + w) {
					dist[it] = dist[t] + w;
					cnt[it] = cnt[t] + 1;
					if (cnt[it] >= 25)return false;
					if (!vis[it]) {
						vis[it] = true;
						que.push(it);
					}
				}
			}
		}
		return true;
	}

	SPFA(int n): n(n), cnt(n + 1), vis(n + 1), dist(n + 1), w(25, 0), tm(25, 0) {};
};
void solve(int T) {
	SPFA s(24);
	for (int x = 1; x <= 24; x++)cin >> s.w[x];
	int n; cin >> n;
	for (int x = 0, i; x < n; x++) {
		cin >> i;
		s.tm[i + 1]++;
	}
	for (int x = 0; x <= 1000; x++) {
		if (s.spfa(x)) {
			cout << x << '\n';
			return;
		}
	}

	cout << "No Solution\n";
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
