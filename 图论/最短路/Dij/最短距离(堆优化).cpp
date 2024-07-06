#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,h[N],w[N],e[N],ne[N],idx,dist[N];
bool vis[N];
//超级源点，dij堆优化
//将所有商店和超级源点的距离为0，即可认为商店和其绑定，这样对所有村庄求其距超级源点的最短路
//即可认为其为所有村庄距离商店的最短路，持续更新所有商店，最后求出的必然是表示询问编号为 yk
//的村庄与其距离最近的商店之间的距离，即相当于每个商店有开向超级源点的传送门，求最短路肯定是
//找到一条路距离超级源点最近，肯定是找到距离最近的商店通过传送门到超级源点。
/*超级源点跟超级汇点是模拟出来的虚拟点，多用于图中：
<1>同时有多个源点和多个汇点，建立超级源点和超级汇点

<2>同时有多个源点和一个汇点，建立超级源点

<3>同时有多个汇点和一个源点，建立超级汇点*/
void add(int a,int b,int c){
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	//a->b的权重，该边的->b，该点连接上一个a点为首的边,动态更新以a点为首的最近连的边，idx边的代号
}
void dij(){
	memset(dist,INF,sizeof dist);//距离初始化无穷
	dist[0]=0;//源点初始化，源点到本身为0
	priority_queue<PII,vector<PII>,greater<PII>>heap;//小根堆
	heap.push({0,0});//从源点开始
	while(heap.size()){
		PII t=heap.top();
		heap.pop();	
		int ver=t.ss,distence=t.ff;//取出节点，及其到源点距离
		if(vis[ver])continue;//去重复操作
		vis[ver]=1;//每一次都会取出距离源点最近的未被标记的点，标记该点
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>distence+w[i]){
				dist[j]=distence+w[i];
				heap.push({dist[j],j});
			}
		}
		//更新距离，将更新后的放入小根堆，堆顶自动为距离源点最近的节点
	}
}
void solve() {
	memset(h,-1,sizeof h);
	cin>>n>>m;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
        add(b,a,c);
	}
	int k;
	cin>>k;
	while(k--){
		int i;
		cin>>i;
		add(0,i,0);
		add(i,0,0);//去掉无影响，因为我们求的是0点到其它点的最短路，只要0->other就行
	}
	dij();
	int q;
	cin>>q;
	while(q--){
		int i;
		cin>>i;
		cout<<dist[i]<<endl;
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
