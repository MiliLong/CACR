#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e3+10,INF=0x3f3f3f3f;
int n,l;
bool g[N][N],st[N];//有向的信息用邻接矩阵很合适；
using namespace std;
int bfs(int s){
	//bfs用队列装；
	memset(st,false,sizeof st);
	st[s]=true;
	queue<pair<int,int>>q;
	q.push({s,0});
	int cnt=0;
	while(!q.empty()){
		//这是异于dfs之处，dfs都是调用自己；
		//bfs则while循环，将所需处理的任务放入queue里；
		auto t=q.front();
		q.pop();//处理完毕记得pop；
		int a=t.ff,b=t.ss;
		for(int x=1;x<=n;x++){
			//遍历所有人；
			if(st[x]||!g[a][x])continue;
			st[x]=true;
			if(b+1<=l){
				q.push({x,b+1});
				cnt++;
			}
		}
	}
   	return cnt;
}
void solve() {
	cin>>n>>l;
	for(int x=1;x<=n;x++){
		int m;
		cin>>m;
		for(int y=1;y<=m;y++){
			int md;
			cin>>md;
			g[md][x]=true;//存入邻接矩阵；
			//显然被关注者转发能让关注着看到，则方向为被关注者到关注者；
		}
	}
	int k;
	cin>>k;
	while(k--){
		int m;
		cin>>m;
		cout<<bfs(m)<<endl;
	}

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
