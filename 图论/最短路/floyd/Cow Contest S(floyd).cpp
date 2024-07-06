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
int n,m,g[N][N];
//只要所有的其它点到该点最短路或该点到其它点最短路存在，就能确定该点在总点中的相对位置
//a->b存在，求得满足的点数即得到比a小的个数，反之则比a大的个数，总和为n-1，即可确定a的位置
//总结::用floyd判断连通性
void floyd(){
	for(int z=1;z<=n;z++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
			}
		}
	}
}
void solve() {
	cin>>n>>m;
	for(int x=0;x<=n;x++){
		for(int y=0;y<=n;y++){
			if(x==y)g[x][y]=0;
			else g[x][y]=INF;
		}
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		g[a][b]=1;
	}	
	floyd();
	int res=0;
	for(int x=1;x<=n;x++){
		bool pd=true;
		for(int y=1;y<=n;y++){
			if(!(x==y||g[x][y]!=INF||g[y][x]!=INF)){
				pd=false;
				break;
			}
		}
		if(pd)res++;
	}
	cout<<res<<endl;
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
