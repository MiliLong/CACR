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
int n,m;
void solve() {
	cin>>n>>m;
	vector<vector<int>>g(n+1);
	vector<int>in(n+1);
	while(m--){
		int a,b;
		cin>>a>>b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		in[a]++,in[b]++;
	}//存图，同时记录入度
	vector<int>vis(n+1),on(n+1);//记录查过的，记录在环上的
	vector<int>path;
	function<bool(int,int,int)>dfs=[&](int u,int f,int root){
		if(vis[u]&&u==root){
			on[u]=true;
			path.emplace_back(u);
			return true;
		}//具有环必须dfs回到root，即dfs的end
		if(vis[u])return false;
		vis[u]=true;
		for(auto v:g[u]){
			if(v==f)continue;
			if(v==root)if(dfs(v,u,root)){
				on[u]=true;
				path.emplace_back(u);
				return true;
			}
		}//先找小环，特判某些特殊情况
		for(auto v:g[u]){
			if(v==f)continue;
			if(dfs(v,u,root)){
				on[u]=true;
				path.emplace_back(u);
				return true;
			}
		}
		//原因::dfs目的只是找环是否存在，并顺手记录环的path，但若有多个环
		//根据数据或同一图数据输入先后顺序，先返回的环是随机的，由于，鱼尾是最后加的
		//但鱼尾需要满足不再环上，所有我们寻找环时要考虑能给root留足鱼尾的环，
		/*
						1			
						|
				2		|       3
                        4
                        |
                        |
                        5
           此时root为4，in[4]=4,显然大环是不行的，连接root两端的点占两个入度，此时我们
           环上最多额外有4-2-2=0个入度的分配，但此时我们有2+1个入度，这是不符合题意的，
           若选择小环则会有2+0个入度，还剩2个入度留给鱼尾，符合。
		   上面特判，可找出最小环，即找出入度只占有root，2个的环，这样留给鱼尾的入度最少
		   为2，足够。
		*/
		return false;
	};//功能：：判断以该点为root会形成环，并存储path(环)
	for(int x=1;x<=n;x++){
		if(in[x]<4)continue;
		vis.assign(n+1,false);
		if(dfs(x,0,x)){
			cout<<"YES\n"<<path.size()+1<<endl;
			vector<PII>ans;
			for(int y=0;y<path.size()-1;y++){
				ans.emplace_back(path[y],path[y+1]);
			}//环上的点按顺序放入path，只需要挨着的配对即可
			int cnt=0;
			for(auto v:g[x]){
				if(!on[v]){
					ans.emplace_back(x,v);
					if(++cnt==2)break;
				}
			}//随便找两个不在环上的点做鱼尾
			for(auto [u,v]:ans){
				cout<<u<<' '<<v<<endl;
			}
			return;
		}
	}
	cout<<"NO"<<endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
