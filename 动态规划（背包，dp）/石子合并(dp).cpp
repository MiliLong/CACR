#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define PII pair<int ,int>
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
void solve() {
	int n;
	cin>>n;
	int a[n+2],sum[n+2][n+2];
	int dp[n+2][n+2];
	for(int x=0;x<=n;x++)for(int y=0;y<=n;y++)dp[x][y]=INF;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		sum[x][x]=a[x];
		dp[x][x]=0;
	}
	//模拟石子合并时，显然整体状态从单堆石子开始，两堆合，状态由此转移，
	//所有从合并石子长度为1开始可完美的转移状态；
	//显然，dp[x][y]=min(dp[x][y],dp[x][z]+dp[z+1][y]+sum[x][y]);
	//记得初始化，即开始状态还有dp初始
	//sum由二维数组求是非常不错的，在过程中现场求sum很好，也可用一维前缀和处理
	for(int l=1;l<n;l++){
		for(int x=1;x<=n-l;x++){
			int y=x+l;
			for(int z=x;z<y/*z!=y,否则会越界，即z+1时出错*/;z++){
				sum[x][y]=sum[x][z]+sum[z+1][y];
				dp[x][y]=min(dp[x][y],dp[x][z]+dp[z+1][y]+sum[x][y]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	//总结：dp显然要找到初始态，以此为基点辐射开来，如本体有长度为1开始，可以使得初始态可以求下一个状态
	//将整个过程连续起来；
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
