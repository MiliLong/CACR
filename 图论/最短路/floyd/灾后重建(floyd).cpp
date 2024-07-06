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
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,g[N][N],aa[N];
bool vis[N];
//中转点若未修建好则跳过，若满足则标记，下一回就不用重复了
//本题是按时间顺序询问的，否则我们要重新排序询问，中转点的问题解决了，但是两端点未修建好怎么办？
//依然进行更新，那么我们讨论一下如果此时更新的操作的数据是否对之后更新产生错误影响，如若没有，那么
//我们就可以不管它。假设x,y都为未维修，下次使用g[x][y]时x或y为中转点，即为中转点那么，x或y必定有效
//因为我们已经裁剪了无效的更新，那么我们可得每一次floyd求出的最短路的数据中，已经维修好的村庄的最短路
//“保证对于任意一对村庄只会存在一条道路”一定正确，当然我们的询问因为不确定是否维修，则需特判，
//这样哪怕其值不为INF我们也不用担心。还有，由题目那么可知一旦发生更新就一定是最短路(更新前后值不同的情况下)
//，所以不用担心我们输出的值会有更小的。
//总结：：floyd的剪枝有奇效！！！
void init(){
	for(int x=0;x<n;x++)for(int y=0;y<n;y++){
		if(x!=y)g[x][y]=INF;
		else g[x][y]=0;
	}
}
void floyd(int c){
	for(int z=0;z<n;z++)if(aa[z]<=c&&!vis[z]){
		vis[z]=true;
		for(int x=0;x<n;x++)for(int y=0;y<n;y++){
		g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
	}
	}
}
void add(int a,int b,int c){
	g[a][b]=c;
	g[b][a]=c;
}
void solve() {
	int a,b,c;
	cin>>n>>m;
	init();
	for(int x=0;x<n;x++)cin>>aa[x];
	for(int x=0;x<m;x++){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	int q;cin>>q;
	while(q--){
		cin>>a>>b>>c;
		floyd(c);
		if(g[a][b]==INF||aa[a]>c||aa[b]>c)cout<<-1;
		else cout<<g[a][b];
		cout<<endl;
	}	
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
