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
int n, m;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt, id[N];
bool is_brage[N];
int d[N], cnt;
vector<vector<PII>>eg(N);
void add(int a, int b, int c) {eg[a].emplace_back(b, c);}
void tarjan(int u, int fname) {
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;

	for (auto [it, name] : eg[u]) {
		if (!dfn[it]) {
			tarjan(it, name);
			low[u] = min(low[u], low[it]);
			if (dfn[u] < low[it])
				is_brage[name] = true;
		} else if (name != fname)low[u] = min(low[u], low[it]);
		//由于无向图无横插边所以不需要in_stk[]来防止已经产生的边连通分量的点集
		//的影响，只需要略过反向边即可
		//为什么dfn[u]<=low[it]不行，为什么加name != fname?
		//1:不能等于，因为相等代表者子连通块有边能连到父节点上，改变就不被判定为桥
		//2：不能被反向边更新low[u]，否则必定存在dfn[u]==low[it]，可看1问题
		//总结:判断桥的存在是通过子节点不能通过任意一条路径(除去反向边的路径)通向父节点
	}

	if (dfn[u] == low[u]) {
		++dcc_cnt;
		int y;
		do {
			y = stk[top--];
			id[y] = dcc_cnt;
		} while (y != u);
	}
}
void solve(int T) {
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		add(u, v, m + 1); add(v, u, m + 1);
	}

	for (int x = 1; x <= n; x++) {
		if (!dfn[x])
			tarjan(x, 0);
	}

	for (int x = 1; x <= n; x++) {
		for (auto [it, name] : eg[x]) {
			if (is_brage[name])
				d[id[it]]++;
		}
	}

	for (int x = 1; x <= dcc_cnt; x++)
		if (d[x] == 1)cnt++;

	cout << (cnt + 1) / 2 << '\n';
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
