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
const int N = 2e6+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,idx,h[N],w[N],e[N],ne[N],dist[N],as[N]/*as[]数组存路的条数*/;
bool vis[N];
//dij堆优化模板
void add(int a,int b,int c){
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dij(){
	memset(dist,INF,sizeof dist);
	dist[1]=0;
	as[1]=1;//初始化，初始点到自身只有一条路
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	heap.push({0,1});
	while(heap.size()){
		PII t=heap.top();
		heap.pop();
		int ver=t.ss,distence=t.ff;
		if(vis[ver])continue;
		vis[ver]=1;
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>distence+w[i]){
				dist[j]=distence+w[i];
				as[j]=as[ver];//更新为更短，as[j]=as[ver]
				heap.push({dist[j],j});
			}
			else if(dist[j]==distence+w[i]){
				as[j]+=as[ver];//之后所有最短路都叠加
				as[j]%=100003;
				//如果又出现个更短的，as[j]=as[ver]，之前叠加的无影响
			}
		}
	}
}
void solve() {
	memset(h,-1,sizeof h);
	cin>>n>>m;
	int a,b;
	while(m--){
		cin>>a>>b;
		add(a,b,1);
		add(b,a,1);
	}
	dij();
	for(int x=1;x<=n;x++)cout<<as[x]<<endl;
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
