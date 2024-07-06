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
int a[N],b[N];
void solve() {
	int n,q;
	cin>>n>>q;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=3;x<=n;x++){
		if(a[x-2]>=a[x-1]&&a[x-1]>=a[x]){
			b[x]=1;
		}
	}
	for(int x=1;x<=n;x++)b[x]+=b[x-1];
	while(q--){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		if(len<=2||r<=2)cout<<len<<endl;
		else {
			cout<<len-(b[r]-b[l+1])<<endl;
		}
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
