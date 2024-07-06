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
//枚举option1和option2的数量，和为k
int sum=0,a[N];
int n,k;
void solve() {
	sum=0;
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		sum+=a[x];
	}
	sort(a+1,a+n+1);
	for(int x=1;x<=n;x++)a[x]+=a[x-1];
	int m=1e18;
	for(int x=0;x<=k;x++){
		m=min(m,a[x*2]+a[n]-a[n-(k-x)]);
	}
	cout<<sum-m<<endl;
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
