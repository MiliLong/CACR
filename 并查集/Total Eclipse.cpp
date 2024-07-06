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
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
int n, m, h[N], e[N], ne[N], idx, p[N];
bool vis[N];
struct Node {
	int w, pos;
	bool operator<(const Node &W)const {
		return w > W.w;
	}//结构体排序重载<
} pt[N];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}//邻接表,加边
void init() {
	for (int x = 0; x <= n; x++) {
		p[x] = x;
		h[x] = -1;
		vis[x] = false;
	}
	idx = 0;
}//初始化
int find(int a) {
	if (p[a] != a)p[a] = find(p[a]);
	return p[a];
}//并查集find函数
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> pt[x].w, pt[x].pos = x;
	pt[n + 1].w = 0;
	sort(pt + 1, pt + n + 1); //按亮度降序排
	init();
	while (m--) {
		int a, b; cin >> a >> b;
		add(a, b), add(b, a);
	}
	int cnt = 0; //统计当前亮度的连通块的数量
	//对于每个加入的城市先假设是独立的，即连通块数量++，之后遍历其相连的以经加入过的城市
	//加入并查集，连通块--，若没连的，显然是新的连通块
	int sum = 0;
	for (int x = 1; x <= n; x++) {
		cnt++;
		int u = pt[x].pos;
		vis[u] = true; //标记这个城市已经加入统计了，可以参与之后的信息统计
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (vis[j]) {
				if (find(u) != find(j)) {
					p[find(j)] = find(u);
					cnt--;
				}
			}
		}
		/*
		直接叙述不会理解，现在模拟过程：：
		对于初始每一个连通块：：
		 1:0
		 2:0 0 0
		 3:000 0
		 4:00000
		 我们统计操作次数时从下往上，1+2+3+1，4为一个连通块，3为2个，2为3个，1为1个
		 接下来我们倒着推，由于已经排序过，我们先拿亮度为4的，记为1个连通块，统计操作时数量为1，亮度由4->3
		 标记该点，接下来我们拿第三列，其亮度为3，此时连通块为2，其遍历连的在场的城市加入并查集，连通块为1
		 统计操作，但后面还有一个亮度为3的，但我们再次遍历边时加入并查集操作会把cnt减小为0，将不计入此次
		 之后以此类推。显然若初始多个连通块那就不会出现减为0的操作，再次统计呗。
		*/

//      这里文字描述不明显，而且理解不是很透彻，直接脑子里模拟水淹没群山(倒置播放)的动态图，cnt详细来说
//		是实时统计当前遍历到的城市的<亮度>，该亮度城市的连通块数量

		sum += cnt * (pt[x].w - pt[x + 1].w); //对于每个连通块进行将其亮度降为当前所有城市第二大的亮度
		//实时加上操作区域数量*每个区域操作次数
		//操作保证当前加入统计的城市亮度都为pt[x].w,这次操作后默认城市亮度变为pt[x+1].w，即
		//与下一次循环的城市的亮度相同
	}
	cout << sum << endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
