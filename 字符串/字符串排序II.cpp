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
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
bool is[N];
bool cmp(pair<char,int>a,pair<char,int>b){
    char aa=tolower(a.ff),bb=tolower(b.ff);
    if(aa!=bb)return aa>bb;
    return a.ss>b.ss;
}
void solve() { 
	string s;
	while(getline(cin,s)){
	    memset(is,false,sizeof is);
	    int l=s.size();
	    vector<pair<char,int>>ans;
	    for(int x=0;x<l;x++){
	        if(isalpha(s[x])){
	            is[x]=true;
	            ans.push_back({s[x],x});
	        }
	    }
	   sort(all(ans),cmp);
	   for(int x=0;x<l;x++){
	       if(is[x]){
	         cout<<ans.back().ff;
	         ans.pop_back();
	       }
	       else cout<<s[x];
	   }
	    cout<<endl;
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