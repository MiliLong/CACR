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
//标准分组背包
int n,v,dp[N],a,b,s,vv[N][N],ww[N][N];
void solve() {
    cin>>n>>v;
    for(int x=1;x<=n;x++){
        cin>>s;
        vv[x][0]=ww[x][0]=s;
        for(int y=1;y<=s;y++){
            cin>>vv[x][y]>>ww[x][y];
        }
    }
    memset(dp,0,sizeof dp);
    //基础工作，读取，初始化
    for(int x=1;x<=n;x++){
        //读取每一组
        for(int y=v;y>=0;y--){
            //01背包，只不过相当于对每一组来说
            for(int z=1;z<=vv[x][0];z++){
                //每一组取最优情况，最后表现为每一组就取一件物品
                if(y>=vv[x][z])dp[y]=max(dp[y],dp[y-vv[x][z]]+ww[x][z]);
            }
        }  
    }
    //如果是开二维数组dp[i][j] = max(dp[i][j],dp[i-1][j-v[i][k]] + w[i][k]);
    //内两层交换位置是没有影响的，因为无论怎么操作，我们更新状态的数据是i-1层的
    //本回合并未更改，也无法更改，相当于对于每一组的每一个物品都是第一次选，不会
    //被组内的其它物品影响
    //但当我们压缩到一维时，层数压缩，数据就要小心更新，以免对之后更新产生影响
    //由大v由小v更新，那么我们先更新大v，大v对所以组员更新，由于使用的都是小v即
    //上层的数据，每一个都相当于第一次也是唯一一次选，这样可以避免出现问题，若
    //层交换，显然每一组一件物品的更新会使用到前一件物品更新后的状态
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