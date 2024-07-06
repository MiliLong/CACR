#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 4e2+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,g[N][N],t[N][N];//分别建立公路和铁路的[][];
int floyd(int r[][N]){
	//标准floyd模板，最外层for为枚举x,y的中间点，否则报错；
	if(r[1][n]==1)return 1;//如果本身有路就不用跑了，最短为1了；
	//如果没有可能会被极端数据搞超时；
	for(int z=1;z<=n;z++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
		r[x][y]=min(r[x][z]+r[z][y],r[x][y]);
	}
	return r[1][n];
}
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(x==y)g[x][y]=0,t[x][y]=0;
			else g[x][y]=INF,t[x][y]=INF;
		}
	}
	//初始化公路，铁路，先为INF；
	for(int x=1;x<=m;x++){
		int a,b;
		cin>>a>>b;
		t[a][b]=t[b][a]=1;//创建铁路；
	}
	for(int x=1;x<=n;x++)for(int y=1;y<x/*不用重复跑*/;y++){
		if(t[x][y]==INF||t[y][x]==INF){
			g[x][y]=g[y][x]=1;//不是铁路就是公路；
		}
	}
	int lg=floyd(g),lt=floyd(t);
	//跑的过程中显然汽车和火车不可能同时到一个地方，若汽车能到且时间>1显然两者无铁路
	//那么有公路，时间为1，反之亦然，即肯定不相等；
	if(lg==INF||lt==INF)cout<<-1<<endl;
	else cout<<max(lg,lt);
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
