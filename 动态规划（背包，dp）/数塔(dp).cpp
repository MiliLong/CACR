#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define af(x,a) for(int x=1;x<=a;x++)
#define PII pair<int ,int>
const int N = 1e6+10;
using namespace std;
//找到状态转移方程，正常初始化就可。
//dp表示从顶层到该位置叠加的最大值，dp由左上，上的dp决定，自此从上往下更新即可。
void solve() {
	int n;
	cin>>n;
	int a[n+1][n+1];
	int dp[n+1][n+1];
	for(int x=1;x<=n;x++){
		for(int y=1;y<=x;y++){
			cin>>a[x][y];
			dp[x][y]=-1;
		}
	}
	dp[1][1]=a[1][1];
	for(int x=1;x<=n;x++){
		if(x==1)continue;
		for(int y=1;y<=x;y++){
			if(y<=x-1)dp[x][y]=max(dp[x][y],dp[x-1][y]+a[x][y]);
			if(y-1>=1&&y-1<=x-1)dp[x][y]=max(dp[x][y],dp[x-1][y-1]+a[x][y]);
		}
	}
	int M=0;
	af(f,n){
		M=max(dp[n][f],M);
	}
	cout<<M<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
