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
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
int ans=INF,n,g[101][101];
bool vis[101];
void dfs(int u,int s){
	if(u==n+1){
		ans=min(ans,s);
		return;
	}
	if(s>ans)return;
	for(int x=1;x<=n;x++){
		if(!vis[x]){
			vis[x]=true;
			dfs(u+1,s+g[x][u]);
			vis[x]=false;
		}
	}
}
void solve() {
	cin>>n;
	for(int x=1;x<=n;x++)for(int y=1;y<=n;y++)cin>>g[x][y];
	dfs(1,0);
	cout<<ans<<endl;	
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
