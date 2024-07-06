#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//核心：：开long long
string s;
void solve() {
	while(cin>>s){
		int l=s.size(),res=0;
		reverse(all(s));//string逆置函数：：reverse(反向)
		for(int x=0;x<l;x++){
			res+=(pow(2,x+1)-1)*(s[x]-'0');
		}
		cout<<res<<endl;
	}
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
