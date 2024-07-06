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
	int f=0;
	map<char,bool>mp;
	if(s.size()==1){
		cout<<"NaN"<<endl;
		return;
	}
	for(int x=0;x<s.size();x++){
		if(mp.count(s[x])==0){
			mp[s[x]]=1;
			bool ans=true;
			for(int y=x+1;y<s.size();y++){
				if(s[y]!=s[s.size()-y+x]){
					ans=false;
					break;
				}
			}
			if(ans){
				cout<<"HE"<<endl;
				return;
			}
		}
		else {
			break;
		}
	}
	
	cout<<"NaN"<<endl;
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
