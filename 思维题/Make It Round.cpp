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
int to(int u){
	while(u%10==0&&u!=0){
		u/=10;
	}
	return u;
}
void solve() {
	int n,m;cin>>n>>m;
	while(to(n)%2==0&&m>=5){
		n*=5,m/=5;
	}
	while(to(n)%5==0&&m>=2){
		n*=2,m/=2;
	}
	while(m>=10){
		n*=10,m/=10;
	}
	cout<<n*m<<'\n';
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
