#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
//#define int long long
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
//此题正解是dij+toport
//用双端队列或优先队列让最短的排前面可以优化性能
int t, r, p, s, idx, e[N], ne[N], h[N], dist[N], w[N];
bool vis[N];
void add(int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void spfa() {
	deque<int>heap;
	dist[s] = 0;
	vis[s] = true;
	heap.push_front(s);
	while (heap.size()) {
		int t = heap.front();
		heap.pop_front();
		vis[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!vis[j]) {
					vis[j] = true;
					if (!heap.empty() && dist[j] < dist[heap.front()])heap.push_front(j);
					else heap.push_back(j);
				}
			}
		}
	}
}
void solve() {
	cin >> t >> r >> p >> s;
	memset(h, -1, sizeof h);
	memset(dist, INF, sizeof dist);
	while (r--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	while (p--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	spfa();
	for (int x = 1; x <= t; x++) {
		if (dist[x] == INF) {
			cout << "NO PATH" << endl;
		}
		else cout << dist[x] << endl;
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> t;
	while (T--) {
		solve();
	}
	return 0;
}