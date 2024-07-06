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
const int N = 1e5+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,w[N];
struct Node{
	int l,r;
	int _min;
}tr[N*4];
void pushup(int u){
	tr[u]._min=min(tr[u<<1]._min,tr[u<<1|1]._min);
}
void build(int u,int l,int r){
	if(l==r)tr[u]={l,r,w[r]};
	else {
		tr[u]={l,r};
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		pushup(u);
	}
}
int query(int u,int l,int r){
	if(tr[u].l>=l&&tr[u].r<=r)return tr[u]._min;
	else {
		int _min=INF;
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)_min=min(_min,query(u<<1,l,r));
		if(r>mid)_min=min(_min,query(u<<1|1,l,r));
		return _min; 
	}
}
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>w[x];
	build(1,1,n);
	while(m--){
		int l,r;cin>>l>>r;
		cout<<query(1,l,r)<<' ';
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
