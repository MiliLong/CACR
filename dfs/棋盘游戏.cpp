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
//dfs+剪枝
int g[6][6];
int a1,a2,b1,b2,ans=INF,dx[]={0,-1,0,1},dy[]={1,0,-1,0};
bool vis[6][6];
void dfs(int a,int b,int d,int s){
	if(a==a2&&b==b2){
		ans=min(ans,s+g[a][b]*d);
		return;
	}
	if(s>=ans)return;
	for(int x=0;x<4;x++){
		int na=a+dx[x],nb=b+dy[x];
		if(na<=5&&na>=0&&nb<=5&&nb>=0&&!vis[na][nb]){
			vis[na][nb]=true;
			dfs(na,nb,(g[a][b]*d)%4+1,s+g[a][b]*d);
			vis[na][nb]=false;
		}
	}
}
void solve() {
	for(int x=0;x<6;x++)for(int y=0;y<6;y++)cin>>g[x][y];
	cin>>a1>>b1>>a2>>b2;
	vis[a1][b1]=true;
	for(int x=0;x<4;x++){
		int na=a1+dx[x],nb=b1+dy[x];
		if(na<=5&&na>=0&&nb<=5&&nb>=0){
			vis[na][nb]=true;
			dfs(na,nb,1,0);
			vis[na][nb]=false;
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
