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
const int N = 5e3+10,INF=0x3f3f3f3f;
using namespace std;
int a[N];
//区间dp,f[l][r]表示l->r排序的代价
void solve() {
	int n,ans=0;cin>>n;
	for(int x=1;x<=n;x++)cin>>a[x];
	vector<vector<int>>f(n+1,vector<int>(n+1));
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(len==1)f[l][r]=0;
			else {
				if(a[l]>a[r])f[l][r]=r-l;//遇到这种情况肯定是必排序，且代价已知
				else f[l][r]=f[l][r-1]+f[l+1][r]-f[l+1][r-1];
				//容斥原理
				//l->r=(l+1->r)+(l->r-1)-(l+1->r-1),两区间代价减去重复排序代价
				ans+=f[l][r];
			}
		}
	}
	cout<<ans<<'\n';
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
