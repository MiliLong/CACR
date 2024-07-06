#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e1+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,k;
int a[N][N],xx[4]={1,-1,0,0},yy[4]={0,0,1,-1},h[1000300],ans=0;//哈希，偏移量
void dfs(int s,int x,int y,int deep){
	//最简单的dfs，deep代表dfs最深深度；
	if(deep==0){
		if(h[s]==0){
			h[s]=1;
			ans++;
		}
		return;
	}
	for(int z=0;z<4;z++){
		int nx=x+xx[z],ny=y+yy[z];
		if(nx<=n&&nx>=1&&ny<=m&&ny>=1)dfs(s*10+a[nx][ny],nx,ny,deep-1);
	}
}
void solve() {
	cin>>n>>m>>k;
	memset(h,0,sizeof h);
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++)cin>>a[x][y];
	for(int x=1;x<=n;x++)for(int y=1;y<=m;y++){
		dfs(a[x][y],x,y,k);
	}
	cout<<ans<<endl;
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
