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
	vector<vector<PII>>eg;
	vector<int>cnt, vis, dist;

	bool spfa(int st) {
		dist.insert(dist.begin(), n + 1, -INF);
		cnt.insert(cnt.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, false);
		queue<int>que;
		dist[st] = 0;
		vis[st] = true;
		que.push(st);
		int count = 0;
		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = false;

			for (auto [it, w] : eg[t]) {
				if (dist[it] < dist[t] + w) {
					dist[it] = dist[t] + w;
					if (++count >= 4 * n)return false;
					cnt[it] = cnt[t] + 1;
					if (cnt[it] >= n + 1)return false;
					if (!vis[it]) {
						vis[it] = true;
						que.push(it);
					}
				}
			}
		}
		return true;
	}
	void add(int a, int b, int w) {
		eg[a].push_back({b, w});
	}

	SPFA(int n): n(n), cnt(n + 1), vis(n + 1), dist(n + 1), eg(n + 1) {};
};
void solve(int T) {
	int n, k; cin >> n >> k;
	SPFA s(n);
	while (k--) {
		int x, a, b; cin >> x >> a >> b;
		if (x == 1)s.add(a, b, 0), s.add(b, a, 0);
		if (x == 2)s.add(a, b, 1);
		if (x == 3)s.add(b, a, 0);
		if (x == 4)s.add(b, a, 1);
		if (x == 5)s.add(a, b, 0);
	}
	for (int x = 1; x <= n; x++)s.add(0, x, 1);
	if (!s.spfa(0))cout << -1 << '\n';
	else {
		int res = 0;
		for (int x = 1; x <= n; x++)res += s.dist[x];
		cout << res << '\n';
	}
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
