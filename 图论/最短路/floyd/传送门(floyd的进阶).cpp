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
const int N = 1e2+10,INF=0x3f3f3f3f;
using namespace std;
//总结：：先跑一遍Floyd，备份，然后枚举所有可能的传送门对，之后对对的两栋楼分别为转折点
//跑Floyd
int n,m,g[N][N],backup[N][N],ans=INF;
void floyd(){
	for(int z=1;z<=n;z++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
		g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
	}
} 
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(x==y)g[x][y]=0;
			else g[x][y]=INF;
		}
	}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=c;
		g[b][a]=c;
	}
	floyd();
	memcpy(backup,g,sizeof g);
	for(int x=1;x<=n-1;x++){
		for(int y=x+1;y<=n;y++){
			g[x][y]=0;
			g[y][x]=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][x]+g[x][j]);
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][y]+g[y][j]);
				}
			}
			int md=0;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					md+=g[i][j];
				}
			}
			ans=min(ans,md);
			memcpy(g,backup,sizeof backup);
		}
	}
	cout<<ans<<endl;
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
