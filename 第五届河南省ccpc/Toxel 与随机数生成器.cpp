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
	string s;
	cin>>s;
	string beg=s.substr(0,1000);
	for(int x=1000;x<s.size();x++){
		if(s.substr(x,1000)==beg){
			cout<<"NO"<<'\n';
			return;
		}
	}
	cout<<"YES"<<endl;
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
