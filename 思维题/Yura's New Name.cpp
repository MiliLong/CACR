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
	stack<char>st;
	int ans=0;
	for(int x=0;x<s.size();x++){
		char i=s[x];
		if(i=='^')st.push(i);
		else {
			if(st.size()&&st.top()=='^')st.push(i);
			else {
				ans++;
				st.push('^');
				st.push(i);
			}
		}
	}
	if(st.top()=='_'||(st.top()=='^'&&st.size()==1))ans++;
	cout<<ans<<endl;
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
