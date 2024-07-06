#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
bool s[N];
int n,k;
bool check(int m){
	int h=k;
	int dp[n+1];//存最大连续
	bool ss[N];
	for(int x=1;x<=n+1;x++)dp[x]=1,ss[x]=s[x];
	for(int x=1;x<=n;x++){
		if(x!=1){
			if(ss[x]==ss[x-1]){
				if(dp[x-1]>=m){
					//新来的连续大于设定了
					dp[x]=1;
					h--;
					if(h<0){
						return false;//改的次数用尽了还要改，false
					}
					else {
						//整体来看，改当前位为反，当特殊情况时特判
						if(x+1<=n&&ss[x]==ss[x+1]&&m>=2)ss[x]=!ss[x];
						//若以上情况可反，反之若后一位异，改当前位，后一位平白无故多一位连续
						//这时不如改前一位，此时m>=2,一位改前位不能影响前前位，若其不等前位的话
						//不过显然这种情况对m=1时是不可以的
						//以下特判
						else if(m==1)ss[x]=!ss[x];
						//这时只是初处理，对于1的情况应有两种，这里默认不改1位置
						//为什么m大于1时默认1位置不改
						//这时因为改1位置的决策显然是亏的
						//若一个长段连续，改1位置，不如改靠后的位置，这样截两段更短，毕竟m大于1了
						//相当是能截断了
					}
				}
				else dp[x]=dp[x-1]+1;
			}
		}
	}
	return true;
}
void solve() {
	cin>>n>>k;
	//基本二分模板
	//问题在于check和特判
	for(int x=1;x<=n;x++){
		char i;
		cin>>i;
		if(i=='N')s[x]=true;
		else s[x]=false;
	}
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	if(ans==2){
		//当ans=2时需要特判
		s[1]=!s[1];//默认改1位置
		k--;//消耗次数
		if(check(1)){
			cout<<1<<endl;
			return;
		}
	}
	cout<<ans<<endl;
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
