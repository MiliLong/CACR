#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
#define int long long//开long long
const int N = 1e2+10,INF=0x3f3f3f3f;
using namespace std;
int a,b,n;
void solve() {
	cin>>n>>a>>b;
	//特判1
	if(a==1){
		if((n-1)%b==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		return;
	}
	int m=1;
	//任意n如果合法可化为a的多少次方+多少倍的b
	//证明：：如上式*a,还是a的多少+1次方+a倍的多少倍b
	//若+b,同样，所以枚举所有a次方，被n减去，剩下的值mod b==0即合法
	while(m<=n){
		if((n-m)%b==0){
			cout<<"Yes"<<endl;
			return;
		}
		m*=a;
	}
	cout<<"No"<<endl;
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
