#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//模拟
void solve() {
	int n;
	cin>>n;
	int a[n+1],b[n+1];
	set<int>st,z;
	for(int x=1;x<=n;x++){
		int i;
		cin>>i;
		a[x]=i;
		st.insert(i);
	}
	int cnt=0;
	map<int,int>mp[101];
	for(int x=1;x<=n;x++){
		int i;
		cin>>i;
		b[x]=i;
		z.insert(i);
		if(mp[i].count(a[x])){
			mp[i][a[x]]++;
		}
		else mp[i][a[x]]=1;
	}
	for(auto it:z){
		cout<<it<<"={";
		for(set<int>::iterator x=st.begin();x!=st.end();++x){
			if((x)!=st.begin())cout<<',';
			cout<<*x<<'=';
			if(mp[it].count(*x))cout<<mp[it][*x];
			else cout<<0;
		}
		cout<<'}'<<endl;
	}
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
