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
//标准spfa模板::邻接表能更丰富的信息，虚拟源点spfa并不用建虚拟边，直接更新dist放队列即可
int n,m,k,t,idx,h[N],e[N],ne[N],w[N],dist[N],tim[N],have[N],g[N];
bool vis[N];
void add(int a,int b,int c){
	w[idx]=max(tim[a],tim[b]),g[idx]=b,e[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void spfa(){
	queue<int>heap;
	for(int x=1;x<=m;x++){
		dist[have[x]]=0;
		heap.push(have[x]);
		vis[have[x]]=true;
	}//在这里不用将点位与0建边了，直接提前更新dist，并标记放入队列即可，其只会被使用dist值，并不会被更新
	//从源点开始，由于这里为虚拟源点，则可以从have里开始放入队列
	//原理：：从源点开始松弛所有相连的点，更新的点放入队列，之后以这一点继续松弛
	//标记点是否在队列里，在就不用在放进去了，不用管更新与否，纯浪费操作，用完点
	//记得取消标记
	//截止循环条件为所有松弛操作不再能更新
	while(heap.size()){
		int t=heap.front();
		vis[t]=false;
		heap.pop();
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>max(dist[t],dist[g[i]])+w[i]){
				dist[j]=max(dist[t],dist[g[i]])+w[i];
				//疑问：：为什么是max(),而不是dist[t],难道g[i]点不会更新吗？
				//答案是：：否，并且问题无效。因为dist[j]并不是单纯的最短时间
				//合成j是需要两个作物的，若按先前的想法，答案肯定会更短，但是
				//错误，因为更新最短时间要通过两个作物的最短时间的max,这样我们
				//才能拥有这两个作物,并通过其更新
				if(!vis[j]){
					vis[j]=true;
					heap.push(j);
				}
			}
		}
	}
}
void solve() {
	memset(h,-1,sizeof h);
	memset(dist,INF,sizeof dist);
	cin>>n>>m>>k>>t;
	for(int x=1;x<=n;x++)cin>>tim[x];
	for(int x=1;x<=m;x++)cin>>have[x];
	while(k--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	spfa();
	cout<<dist[t]<<endl;
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
