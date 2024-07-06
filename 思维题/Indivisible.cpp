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
void solve() {
	int n;
	cin>>n;
	int l=n-1,r=n;
	if(n==1){
		cout<<1<<endl;
		return;
	}
	if(n&1){
		cout<<"-1"<<endl;
		return;
	}
	for(int x=0;x<n;x++){
		if(x)cout<<' ';
		if(x&1){
			cout<<r;
			r-=2;
		}
		else {
			cout<<l;
			l-=2;
		}
	}
	cout<<endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}