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
//分奇偶讨论
//输出从1到n，可得从2到2n，这样可以把(2n-1)个的构造出，即奇数情况
//偶数2，4特判掉，剩下的输出1到n但把2排除，即n-1个，可构造(n-1)*2的情况
//即偶数情况
void solve() {
	int n;
	cin>>n;
	int nn=(n+1)/2;
	if(n==2||n==4){
		cout<<-1<<endl;
		return;
	}//特判掉
	if(n%2==1){
	cout<<nn<<endl;	
	for(int x=1;x<=nn;x++)cout<<x<<' ';
	}
    else {
    	cout<<n/2<<endl;
    	for(int x=1;x<=n/2+1;x++)if(x!=2)cout<<x<<' ';
    }

}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
