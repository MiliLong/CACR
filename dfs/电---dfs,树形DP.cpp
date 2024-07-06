#include<bits/stdc++.h>
//#pragma GCC optimize (1)
//#pragma GCC optimize (2)
//#pragma GCC optimize (3)
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
//dfs/树形DP,无环
int cnt;
void solve() {
	cnt++;
	int n;cin>>n;
	int a[n+1],res[n+1];
	for(int x=1;x<=n;x++)cin>>a[x],res[x]=0;
	vector<vector<int>>h(n+1);
	int ans=-1;
	for(int x=0;x<n-1;x++){
		int i,j;cin>>i>>j;
		h[i].emplace_back(j);
		h[j].emplace_back(i);
	}
	function<void(int)>dfs=[&](int f){
		res[f]=1;
		for(auto it:h[f]){
			if(a[f]>a[it]){
				if(res[it]==0)dfs(it);
				res[f]+=res[it];
			}
		}
	};
	for(int x=1;x<=n;x++){
		if(res[x]==0)dfs(x);
		ans=max(ans,res[x]);
	}
	printf("Case #%lld: %lld\n",cnt,ans);
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
