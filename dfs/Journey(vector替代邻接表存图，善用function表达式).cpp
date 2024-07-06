#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//存图用vector，function表达式
void solve() {
	int n;
	double ans=0;
	cin>>n;
	vector<vector<int>> g(n + 1);
	cout<<fixed<<setprecision(15);
	for(int x=0;x<n-1;x++){
		int a,b;
		cin>>a>>b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	function<void(int,int,int,double)>dfs=[&](int a,int f,int d,double p){
		if(g[a].size()==1&&a!=1){
			ans+=d*p;
			return;
		}
		double son=g[a].size()-(a!=1);
		for(auto it:g[a]){
			if(it==f)continue;
			dfs(it,a,d+1,p/son);
		}
	};
	dfs(1,0,0,1);
	cout<<ans<<endl;
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
