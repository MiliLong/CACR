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
int n,m,s,h[N],w[N],e[N],ne[N],idx,dist[N];
bool vis[N];
void add(int a,int b,int c){
	w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dij(){
	memset(dist,INF,sizeof dist);
	dist[s]=0;
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	heap.push({0,s});
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
				heap.push({dist[j],j});
			}
		}
	}
}
void solve() {
	memset(h,-1,sizeof h);
	cin>>n>>m>>s;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	dij();
	for(int x=1;x<=n;x++){
		if(dist[x]>2147483647)cout<<2147483647<<' ';
		else cout<<dist[x]<<' ';
	}
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
