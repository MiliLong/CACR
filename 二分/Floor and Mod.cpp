#include<bits/stdc++.h>
//#pragma GCC optimize (1)
//#pragma GCC optimize (2)
//#pragma GCC optimize (3)
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
int i,j;//枚举所有余数，二分所有对应余数的最大[j];
void solve() {
	cin>>i>>j;
	int ans=0;int mx=sqrt(i);
	for(int x=1;x<=mx;x++){
		if(x>=j)break;
		int l=x,r=j;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(mid*x+x<=i)l=mid;
			else {
				r=mid-1;
			}	
		}
		ans+=r-x;
	}
	cout<<ans<<'\n';
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
