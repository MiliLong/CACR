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
int a[N],tree[N];
int n,k,op;
//开树状数组存一个位置的被操作数，读取时再操作，并清空操作数，通过差分实现
//区间加值，查询单点
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int a,int b){
	for(int x=a;x<=n;x+=lowbit(x))tree[x]+=b;
}
inline int sum(int a){
 	int res=0;
 	for(int x=a;x;x-=lowbit(x))res+=tree[x];
 	return res;
}
inline int to(int u){
	int ans=0;
	while(u){
		ans+=u%10;
		u/=10;
	}
	return ans;
}
void solve() {
	cin>>n>>k;
	for(int x=1;x<=n;x++)cin>>a[x],tree[x]=0;
	while(k--){
		cin>>op;
		if(op==1){
			int l,r;cin>>l>>r;
			add(l,1),add(r+1,-1);
		}
		else if(op==2){
			int u;cin>>u;
			int left=sum(u);
			for(int x=1;x<=left;x++){
				a[u]=to(a[u]);
				if(a[u]<=9)break;//及时剪枝
			}
			cout<<a[u]<<'\n';
			add(u,-left),add(u+1,+left);
		}
	}
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
