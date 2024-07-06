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
int a[N+1];
void solve() {
	int n,h,ans=0,ans1=0,ans2=0;cin>>n>>h;
	for(int x=1;x<=n;x++)cin>>a[x];
	sort(a+1,a+n+1);
	int u=1,hh=h;
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans++;
		else {
			hh*=3;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans++;
		else {
			break;
		}
	}
	u=1,hh=h;
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans1++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans1++;
		else {
			hh*=3;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans1++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans1++;
		else {
			break;
		}
	}
	u=1,hh=h;
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans2++;
		else {
			hh*=3;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans2++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans2++;
		else {
			hh*=2;
			break;
		}
	}
	while(u<=n){
		if(a[u]<hh)hh+=a[u]/2,u++,ans2++;
		else {
			break;
		}
	}
	ans=max(ans,max(ans1,ans2));
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
