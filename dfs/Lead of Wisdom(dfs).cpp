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
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//dfs爆搜,卡常
//数组更快
int n,m,cnt[55],g[55][55][55],ans,ne[55];
void dfs(int u,int a,int b,int c,int d){
	if(u==m+1){//到m+1,代表遍历完,开始更新
		ans=max(ans,a*b*c*d);
		return;
	}
	if(!cnt[u])dfs(ne[u],a,b,c,d);//当前组不存在往下一个存在的组跳,不存在的for循环无用
	for(int i=1;i<=cnt[u];i++){
		dfs(u+1,a+g[u][i][0],b+g[u][i][1],c+g[u][i][2],d+g[u][i][3]);
	}
}
void solve() {
	cin>>n>>m;
	for(int x=0;x<=51;x++)cnt[x]=0;
	for(int i=0;i<n;i++){
		int o;cin>>o;
		cnt[o]++;
		for(int j=0;j<4;j++)cin>>g[o][cnt[o]][j];
	}
    int x=m+1;
    for(int i=x;i>=1;i--){
    	ne[i]=x;
    	if(cnt[i])x=i;
    }//每组物品连接下一组物品的类别，最后都连到m+1,表示结束
	ans=pow(100,4);
	dfs(1,100,100,100,100);
	cout<<ans<<endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
