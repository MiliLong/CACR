#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 3e4+10,INF=0x3f3f3f3f;
using namespace std;
int f[N],num[N],totop[N];
//核心难题如何找到飞船之间的间隔飞船数量
//可转化为飞船到队头的距离差-1
//由并查集特性，一个特定飞船到船头个find过程中，由该飞船到最初的飞船船头，船头再到船头
//直到找到真正的船头
void init(){
for(int x=1;x<=N-1;x++){
	f[x]=x;
	num[x]=1;//船头为首的那一列总船
	totop[x]=0;//飞船到船头距离
}
}
int find(int a){
	if(f[a]==a)return a;
	int fn=find(f[a]);
	totop[a]+=totop[f[a]];//a到其父的距离更新为到总船头的距离
	//只需要a到父加上父到父父即可
	//更新操作只会进行一次，因为之后f[a]=fn,更新完毕了
	return f[a]=fn;
}
void Union(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa!=fb){
		//对于每一次Union操作，对两个船头进行的操作最容易
		totop[fa]+=num[fb];//fa到新船头的距离相当于fa前面又多了num[fb]个船，加上即可，+=因为fa前面可以放多次船，=就会重置
		f[fa]=fb;
		num[fb]+=num[fa];//新船头num更新
		//num[fa]=0;//老船头不再为船头，则num为0//不必有这步，老船头，之后的sum不在调用了
		//以上操作为新老船头的信息更新
		//但只是船头间的更新，还有很多船需要进行更新，那么可以放在find函数里进行操作，节省时间
	}
}
//总结：：花了好几个小时想，值得细看
void solve() {
	int n;
	cin>>n;
	init();
	while(n--){
		char i;
		cin>>i;
		int a,b;
		cin>>a>>b;
		if(i=='M'){
			Union(a,b);
		}
		else {
		    if(a==b)cout<<0<<endl;
			else if(find(a)==find(b)){
				cout<<abs(totop[a]-totop[b])-1<<endl;
			}
			else cout<<-1<<endl;
		}
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
