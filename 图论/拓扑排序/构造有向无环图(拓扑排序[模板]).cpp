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
const int N = 2e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
//理解：：若有拓扑序，我们就可以自己求方向了，(当然我们边是题目给的，但不知道方向),只要所以边的两点都满足拓扑序
//即前点的拓扑序位置比后点靠前，那么必定正确，当然一个图的拓扑序不是一定仅有一个哦
int n, m, idx, e[N], ne[N], h[N], d[N], s[N], q[N];
pair<int, int>edge[N];
//除了，idx，h[]，d[]需要初始化，其它不需要，因为使用时会覆盖，原来的数据不会影响下一轮
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int topsort() {
	int hh = 0, tt = -1; //为拉使第一次更新tt时为0，第一次使用hh时为0，保证相等，这样下标才能一一对应
	for (int x = 1; x <= n; x++) {
		if (!d[x]) {
			q[++tt] = x, s[x] = tt;
		}
	}
	//q数组模拟bfs队列，若入度为0则加入队列，++tt代表tt从0开始，即最后数组的容量为tt+1
	while (hh <= tt) {
		int t = q[hh++]; //取出当前点编号，hh++
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			//所有该点指向的点的入度--，若为0则加入队列，s[]存拓扑序列中其相对位置
			if (--d[j] == 0) {
				q[++tt] = j, s[j] = tt;
			}
		}
	}
	return tt == n - 1; //若存在拓扑排序，最后拓扑序和总点相等
}
void solve() {
	cin >> n >> m;
	memset(h, -1, (n + 1) * 4);
	memset(d, 0, (n + 1) * 4); //初始化全部会超时,(n+1)个(4)int即可
	idx = 0; //初始化
	for (int x = 0; x < m; x++) {
		int a, b, t;
		cin >> t >> a >> b;
		if (t)add(a, b), d[b]++; //入度++
		edge[x] = {a, b}; //存边
	}
	if (!topsort()) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int x = 0; x < m; x++) {
			auto &t = edge[x];
			if (s[t.ff] < s[t.ss])cout << t.ff << ' ' << t.ss << endl;
			//之后的点满足拓扑序即可，即输出的左a,右b,a点比b先剔除，即s[a]<s[b](本题不会考虑顺序，只要满足即可)
			//显然t=1的点肯定满足，不满足"NO"过了
			else cout << t.ss << ' ' << t.ff << endl;
		}
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
