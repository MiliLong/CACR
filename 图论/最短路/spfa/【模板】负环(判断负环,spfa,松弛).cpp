#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long
using ll = long long;
const int N = 1e7 + 10, INF = 0x3f3f3f3f;
using namespace std;
//Bellman-Ford，进行队列优化即为spfa，Bellman-Ford即为开两个for循环，以每个点为转折点松弛其它点
int n, m, e[N], ne[N], idx, h[N], dist[N], w[N], cnt[N];
bool vis[N];
void add(int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool spfa() {
	queue<int>heap;
	dist[1] = 0;
	vis[1] = true;
	heap.push(1);
	while (heap.size()) {
		int t = heap.front();
		heap.pop();
		vis[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!vis[j]) {
					cnt[j]++;
					if (cnt[j] >= n)return true;
					//由未优化的Bellman-Ford一个点最多被其它n-1个点松弛，若松弛次数>=n显然会存在负环
					//导致环内成员dist一直减小，即一直进行松弛操作
					//判断入队次数而不是松弛次数，防止因重边导致的额外且无意义的松弛而造成的重复计数
					//误判负环，若无重边显然判断松弛操作更快，毕竟入队需特判，导致进行更多松弛操作后才能break
					//即若无重边，判断松弛操作能即刻break，而判断入队操作则会在更多松弛操作后break
					//有延时性(假设此时松弛操作以经>=n,但由于未到入队时机，则需要等待更多轮直到入队后才能break)
					vis[j] = true;
					heap.push(j);
				}
			}
		}
	}
	return false;
}
void solve() {
	idx = 0;
	memset(h, -1, sizeof h);
	memset(dist, INF, sizeof dist);
	memset(vis, false, sizeof vis);
	memset(cnt, 0, sizeof cnt);
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w >= 0)add(u, v, w), add(v, u, w);
		else add(u, v, w);
	}
	bool ans = spfa();
	if (ans)cout << "YES";
	else cout << "NO";
	cout << endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
