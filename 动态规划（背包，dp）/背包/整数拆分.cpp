#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
int n,dp[N];
//完全背包变种
//dp[n]代表数字n的拆分总数（mod后）
void solve() {
    cin>>n;
    dp[0]=1;
    for(int x=1;x<=n;x*=2){
        //相当于在容器里放2的幂
        for(int y=x;y<=n;y++){
            //便利能放该数的情况，dp[y]加上dp[y-x]的总数（相当于y-x的情况都加上x或得y情况）
            dp[y]+=dp[y-x];
            dp[y]=dp[y]%1000000000;
        }
    }
    cout<<dp[n];
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
