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
const int N = 1e2+10,INF=0x3f3f3f3f;
using namespace std;
int g[N][N],n,m,a[200000],ans=0;
void floyd(){
	for(int z=1;z<=n;z++)for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
		g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
	}
} 
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
		if(x==y)g[x][y]=0;
		else g[x][y]=INF;
	}
	for(int x=1;x<=m;x++)cin>>a[x];
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			int i;
			cin>>i;
			g[x][y]=i;
		}
	}	
	floyd();
	for(int x=1;x<m;x++){
		ans+=g[a[x]][a[x+1]];
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
