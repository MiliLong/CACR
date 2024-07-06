#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
//标准01背包
int n,v,dp[N],a,b;
void solve() {
    cin>>n>>v;
    memset(dp,0,sizeof dp);
    for(int x=1;x<=n;x++){
        cin>>a>>b;
        for(int y=v;y>=a;y--){
            dp[y]=max(dp[y],dp[y-a]+b);
        }
    }
    cout<<dp[v];
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
