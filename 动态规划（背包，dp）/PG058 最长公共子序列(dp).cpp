#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define af(x,a) for(int x=1;x<=a;x++)
#define PII pair<int ,int>
const int N = 1e6+10;
using namespace std;
void solve() {
	string s1,s2;
	while(cin>>s1>>s2){
		int l1=s1.size(),l2=s2.size();
		int dp[l1+2][l2+2];
		memset(dp,0,sizeof dp);
		dp[0][0]=0;//初始化极其重要：：0之前为空，则dp[0][0]=0;
		af(x,l1){//dp[x][y]为dp[0>x][0>y],x，y之前最长子串，即0到x-1与0到y-1,字符不包括x，y；
			af(y,l2){
				if(s1[x-1]==s2[y-1]){
					dp[x][y]=dp[x-1][y-1]+1;//若前一个相等显然此处dp等于前一个状态的dp+1，毕竟相当于同时加上一个相等的字符
				}
				else {
				 dp[x][y]=max(dp[x-1][y],dp[x][y-1]);//不等时取两种情况的最大值
				 //dp[x-1][y]相当于将x提前一位看，由于x-1，y-1不等，那么就看x-2，y-1的情况
				 //（相当于假设x-1处无用），dp[x-1][y]已经处理过，肯定正确；
				 //dp[x][y-1]同理
				 //总之，该情况下就是假设加上x-1处无用，或y-1处无用：：其实应该还有两种都无用，其实这种情况已经包含在了两个dp里了；
				}
			}
		}
		cout<<dp[l1][l2]<<endl;
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
