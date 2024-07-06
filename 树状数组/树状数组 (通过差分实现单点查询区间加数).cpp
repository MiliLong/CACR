#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 5e5+10,INF=0x3f3f3f3f;
using namespace std;
//功能：：单点查询（求和），区间加值
int a[N],tree[N];
int n,m;
int lowbit(int x){
	return x&(-x);
}
void add(int a,int b){
	for(int x=a;x<=n;x+=lowbit(x))tree[x]+=b;
}
int sum(int a){
 	int res=0;
 	for(int x=a;x;x-=lowbit(x))res+=tree[x];
 	return res;
}
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=1;x<=n;x++)add(x,a[x]-a[x-1]);
	int to,x,y,k;
	while(m--){
		cin>>to;
		if(to==1){
			cin>>x>>y>>k;
			add(x,k);
			add(y+1,-k);
		}
		else {
			cin>>x;
			cout<<sum(x)<<endl;
		}
	}
}
/*
建树板子已讲
相当于将差分融入进去，整体板子不变，add时add(x,a[x]-a[x-1])即可
此时我们的数组：：
[1](a[1]-a[0]),[2](a[2]-a[1]),[3](a[3]-a[2]),[4](a[4]-a[3]),[5](a[5]-a[4])
此时sum就是单点查询，sum[4]=[1]+[2]+[3]+[4]=a[4]-a[0]=a[4]
add时将区间内每个数加上一个数，假如加k对2-4
[2]+k,[5]-k
在通过2-4的sum时肯定有一步操作加k即得a[4]+k,a[3]+k,a[2]+k,而在5即以后又会减去k
之后的数则不会加k
这里通过差分使得原本求和的sum变为了单点查询，对差分的前n项求和就是第n项
当本质操作还是不变的
*/
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
