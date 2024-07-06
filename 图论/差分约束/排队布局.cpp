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

//最短路求最大值
//最长路求最小值
//最短路被更新值小于等于更新值+边长
//最长路被更新值大于等于更新值+边长
//建边方向：从更新者到被更新者建一条长度为边长的边

//确定相对关系只用在队列里初放两者之一
//确定整体的存在关系将所有元素放入队列求正负环

//求整体关系要保证初始队列元素能遍历到所有元素
//即存在以初始元素为根节点的生成树
//一般可建立超级源点
//如若仅求存在关系可省去超级源点的建边步骤
//转至"确定整体的存在关系将所有元素放入队列求正负环"

class SPFA {
public:
	int n;
	vector<vector<PII>>eg;
	vector<int>vis, dist, cnt;

	bool spfa(int st) {
		dist.insert(dist.begin(), n + 1, INF);
		vis.insert(vis.begin(), n + 1, 0);
		cnt.insert(cnt.begin(), n + 1, 0);

		queue<int>que;
		for (int x = 1; x <= st; x++) {
			que.push(x);
			vis[x] = 1;
			dist[x] = 0;
		}
		int count = 0;
		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = 0;

			for (auto [it, w] : eg[t]) {
				if (dist[it] > dist[t] + w) {
					dist[it] = dist[t] + w;
					//if (++count >= 16 * n)return false;太过玄学不建议写，除非tle
					cnt[it] = cnt[t] + 1;
					if (cnt[it] >= n)return false;
					if (!vis[it]) {
						vis[it] = 1; que.push(it);
					}
				}
			}
		}
		return true;
	}

	void add(int a, int b, int c) {
		eg[a].push_back({b, c});
	}

	SPFA(int n): n(n), dist(n + 1), vis(n + 1), eg(n + 1), cnt(n + 1) {};
};
void solve(int T) {
	int n, i, j; cin >> n >> i >> j;
	SPFA s(n);

	for (int x = 1; x < n; x++) {
		s.add(x + 1, x, 0);
	}
	for (int x = 0; x < i; x++) {
		int a, b, l; cin >> a >> b >> l;
		if (a > b)swap(a, b);
		s.add(a, b, l);
	}
	for (int x = 0; x < j; x++) {
		int a, b, d; cin >> a >> b >> d;
		if (a > b)swap(a, b);
		s.add(b, a, -d);
	}

	if (s.spfa(n)) {
		s.spfa(1);
		if (s.dist[n] == INF)cout << -2 << '\n';
		else cout << s.dist[n];
	}
	else cout << -1 << '\n';
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
