#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
void solve() {
	int n,a;
	cin>>n;
	int ma=0,m=0,f=1/*每一层最高位*/,ff=0/*层内第几位*/,mids=0/*每一层的sum*/,mm=1/*层*/;
	for(int x=1;x<=n;x++){
		cin>>a;
		if(ff<=f){
			mids+=a;
			ff++;
		}
		if(ff==f||x==n/*每一层的末点，和最末要进行特判*/){
			f*=2;
			if(mids>ma){
				ma=mids;
				m=mm;
			}
			ff=0;
			mm++;
			mids=0;
		}
	}
	cout<<m<<endl;
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
