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
	double n,k;cin>>n>>k;
	double ma=min(k-1,n/0.5)+n-0.5*min((k-1),n/0.5);
	if(fmod(ma,1.0)>=0.5)ma++;
	double mn=n-(0.5*min((k-1),n/0.5));
	mn=max(mn,0.0);
	if(fmod(mn,1.0)>=0.5)mn++;
	printf("%d ",(int)mn);
	printf("%d\n",(int)ma);
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
