#include<iostream>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long 
using ll = long long;
const int N = 1e5+10,INF=0x3f3f3f3f;
using namespace std;
//注意结构体内lazy的初始化与加法lazy和乘法lazy的优先级问题(乘法优先,注意时刻更新加法lazy)
int n,m,p,w[N];
struct Node{
    int l,r;
    int sum,add;
    int mt;
}tr[N*4];
void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}
void pushdown(int u){
    auto &root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    left.add=(left.add*root.mt+root.add)%p,left.mt=root.mt*left.mt%p,left.sum=(left.sum*root.mt+root.add*(left.r-left.l+1))%p;
    right.add=(right.add*root.mt+root.add)%p,right.mt=root.mt*right.mt%p,right.sum=(right.sum*root.mt+root.add*(right.r-right.l+1))%p;
    root.add=0;
    root.mt=1;
}
void build(int u,int l,int r){
    tr[u]={l,r,w[r],0,1};
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}
void motify(int u,int l,int r,int d){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum=(tr[u].sum+d*(tr[u].r-tr[u].l+1))%p;
        tr[u].add=(tr[u].add+d)%p;
    }
    else{
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)motify(u<<1,l,r,d);
        if(r>mid)motify(u<<1|1,l,r,d);
        pushup(u);
    }
}
void mul(int u,int l,int r,int d){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum=(tr[u].sum*d)%p;
        tr[u].add=(tr[u].add*d)%p;
        tr[u].mt=(tr[u].mt*d)%p;
    }
    else{
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)mul(u<<1,l,r,d);
        if(r>mid)mul(u<<1|1,l,r,d);
        pushup(u);
    }
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    else {
        pushdown(u);
        int sum=0;
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)sum=(sum+query(u<<1,l,r))%p;
        if(r>mid)sum=(sum+query(u<<1|1,l,r))%p;
        return sum%p;
    }
}
void solve() {
    cin>>n>>m>>p;
    for(int x=1;x<=n;x++)cin>>w[x];
    build(1,1,n);
    while(m--){
        int op,x,y,k;cin>>op;
        cin>>x>>y;
        if(op==1){
            cin>>k;
            mul(1,x,y,k);
        }
        else if(op==2){
            cin>>k;
            motify(1,x,y,k);
        }
        else {
            cout<<query(1,x,y)<<endl;
        }
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