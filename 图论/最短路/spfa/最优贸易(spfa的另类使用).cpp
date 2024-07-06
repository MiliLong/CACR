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
//枚举每一个点位为中转点，该点前的min，后的max
//建立正反邻接表(idx,e,ne不用管，只管h)
//各跑一遍spfa，记得初始化最初的d，两次不同
//用spfa的思想，用当前点的数据去更新之后(有向->)点的数据
int n, m, idx, e[N], ne[N], hh[N], a[N], mn[N], ma[N], rh[N];
bool vis[N];
void add(int *h, int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void spfa(int *dist, int s, bool flag, int *h) {
	queue<int>heap;
	memset(vis, false, sizeof vis);
	dist[s] = a[s];
	vis[s] = true;
	heap.push(s);
	while (heap.size()) {
		int t = heap.front();
		heap.pop();
		vis[t] = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if ((flag && dist[j] > min(dist[t], a[j])) || ((!flag) && dist[j] < max(dist[t], a[j]))) {
				if (flag)dist[j] = min(dist[t], a[j]);
				else dist[j] = max(dist[t], a[j]);
				if (!vis[j]) {
					vis[j] = true;
					heap.push(j);
				}
			}
		}
	}
}
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> a[x];
	memset(hh, -1, sizeof hh);
	memset(rh, -1, sizeof rh);
	memset(mn, INF, sizeof mn);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(hh, a, b), add(rh, b, a);
		if (c == 2) {
			add(hh, b, a), add(rh, a, b);
		}
	}
	spfa(mn, 1, true, hh);
	spfa(ma, n, false, rh);
	int ans = 0;
	for (int x = 1; x <= n; x++) {
		ans = max(ans, ma[x] - mn[x]);
	}
	cout << ans << endl;
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