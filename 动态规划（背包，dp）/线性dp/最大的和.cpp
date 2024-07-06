#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 5e4+10,INF=-0x3f3f3f3f;
using namespace std;
//思路::前后分开，求以为x结尾的1-x区间的最大值，和以x为开头的x-n区间的最大值
//正着来，逆着来。s存以x为结尾或开头的连续区间的值，然后dp随时更新者，最小值
//INT_MIN不可用，用INF=-0x3f3f3f3f。
int a[N],n,f[N],sum[N],g[N],m,s=0;
void solve() {
	cin>>n;
	m=INF;
	memset(f,INF,sizeof f);
	memset(g,INF,sizeof g);
    for(int x=1;x<=n;x++){
        cin>>a[x];
    }
    s=0;
    for(int x=1;x<=n;x++){
        s=max(0,s)+a[x];
        f[x]=max(f[x-1],s);
    }
    s=0;
    for(int x=n;x>=1;x--){
        s=max(0,s)+a[x];
        g[x]=max(g[x+1],s);
    }
    for(int x=1;x<n;x++)m=max(m,f[x]+g[x+1]);
    cout<<m<<endl;
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
