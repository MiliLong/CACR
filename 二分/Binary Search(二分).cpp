#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long 
//using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
using namespace std;
void solve() {
	int n,x,p;
	cin >> n >> x >> p;
	int a=0 , b=0 , l=0 , r=n , mid , ans=1 ;//r开大点也无妨，但若为n-1就会G
	//整体思路，模拟二分过程，若为升序排列，那么二分过程中，左侧的查找和右侧的查找应是固定的
	//左侧恒小右侧恒大，左侧a个右侧b个
	//那么排列时严格遵守左侧a个小右侧b个大即可
	//x-1个选a个排序，n-x个选b个排序，n-a-b-1个排列最后乘mod就行
	while(l < r){
		//<=会卡死
		mid =(l + r) / 2;
		if(mid <= p){
			l = mid+1;
			if(mid!=p)a++;
		}
		else {
			r = mid;
			b++;
		}
	}
	for (int i = x - a; i <= x - 1; ++ i)
        ans = (ans * i) % mod;

    for (int i = n - x - b + 1; i <= n - x; ++ i)
        ans = (ans * i) % mod;

    for (int i = 1; i <= n - a - b - 1; ++ i)
        ans = (ans * i) % mod;
	cout<<ans<<endl;
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
