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
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//模拟除法(模拟正常手算除法过程)
void solve() {
	int n;cin>>n;
	int ans=1,u=1;
	while(u<n){
		u=u*10+1;
		ans++;
	}
	while(1){
		cout<<u/n;
		u=u%n;
		if(u==0)break;
		else {
			u=u*10+1;
			ans++;
		}
	}//边算边输出
	cout<<' '<<ans<<endl;
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
