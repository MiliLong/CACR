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
int n,m,a[N],to;
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++)cin>>a[x];
	while(m--){
		int l=1,r=n,mid,to;
		cin>>to;
		while(l<r){
			mid=(l+r)/2;
			if(a[mid]>=to){
				r=mid;
			}
			else {
				l=mid+1;
			}
		}
		if(a[l]==to)cout<<l;
		else cout<<-1;
		cout<<' ';
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
