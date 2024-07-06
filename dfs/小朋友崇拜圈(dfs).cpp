#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e5+10,INF=0x3f3f3f3f;
using namespace std;
int a[N],ans=0;
bool vis[N];//回溯，防止重复循环，每一个个体除初始外只允许出现一次；
void dfs(int now,int deep,int start){
	if(vis[now])return ;//多次出现，违反，结束；
	if(a[now]==start){
		//找到下一个崇拜位目标；
		ans=max(ans,deep);
		return ;
	}
	vis[now]=true;//标记；
	int next=a[now];
	dfs(next,deep+1,start);//下一次寻找，深度加1；
}
void solve() {
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=1;x<=n;x++){
		memset(vis,false,sizeof vis);
		dfs(x,1,x);
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
