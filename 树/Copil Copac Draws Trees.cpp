#include<bits/stdc++.h>
//#pragma GCC optimize (1)
//#pragma GCC optimize (2)
//#pragma GCC optimize (3)
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
void solve() {
	int n;cin>>n;
	vector<vector<PII>>g(n+1);
	vector<int>s(n+1);
	for(int x=1;x<=n-1;x++){
		int u,v;cin>>u>>v;
		g[u].emplace_back(v,x);g[v].emplace_back(u,x);//存储时间
	}//建树
	int ans=0;
	function<void(int,int,int)>dfs=[&](int u,int tu,int f){
		for(auto [v,tv]:g[u]){
			if(v==f)continue;//防止回搜
			if(tu>tv)s[v]=s[u]+1;//当前轮不能顺序染色只能等下一轮，轮次+1
			else s[v]=s[u];//当前轮可染色，轮次继承
			dfs(v,tv,u);
		}
	};//树上深搜
	s[1]=1;/*赋点1轮次为1*/dfs(1,0,0);
	for(int x=1;x<=n;x++)ans=max(ans,s[x]);//找最大轮染色的点，即结束轮次
	cout<<ans<<'\n';
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
