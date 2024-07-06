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

class Prim {
public:
	int n, _INF = 1e18, siz;
	vector<vector<PII>>eg;
	vector<int>dist, vis, is;
	vector<PII>cb;

	void dfs(int u, int f) {
		for (auto [it, w] : eg[u]) {
			if (it == f || is[it])continue;
			is[it] = 1;
			siz++;
			dfs(it, u);
		}
	}
	void get_cb() {
		for (int x = 1; x <= n; x++) {
			if (!is[x]) {
				siz = 1;
				is[x] = 1;
				dfs(x, 0);
				cb.emplace_back(x, siz);
			}
		}
	}

	int prim(int st, int siz) {
		dist.insert(dist.begin(), n + 1, _INF);
		vis.insert(vis.begin(), n + 1, 0);

		int res = 0, cnt = 0;
		dist[st] = 0;
		priority_queue<PII, vector<PII>, greater<PII>>heap;

		heap.push({dist[st], st});
		while (heap.size()) {
			auto [dis, vir] = heap.top(); heap.pop();

			if (vis[vir])continue;
			vis[vir] = true;
			cnt++;
			if (dis == _INF)return _INF;

			res += dis;

			for (auto [it, w] : eg[vir]) {
				if (dist[it] > w) {
					dist[it] = w;
					heap.push({dist[it], it});
				}
			}
		}
		if (cnt == siz)return res;
		else return _INF;
	}

	int get_ans() {
		get_cb();
		int ans = 0;
		for (auto [it, siz] : cb) {
			ans += prim(it, siz);
		}
		return ans;
	}

	Prim(int in): n(in), eg(in + 1), dist(in + 1), vis(in + 1), is(in + 1, 0) {};

};

void solve() {
	int n, k, sum = 0; cin >> n >> k;

	Prime p(n);
	while (k--) {
		int i, j, m; cin >> i >> j >> m;

		sum += m;
		p.eg[i].emplace_back(j, m);
		p.eg[j].emplace_back(i, m);
	}

	cout << sum - p.get_ans() << '\n';

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
