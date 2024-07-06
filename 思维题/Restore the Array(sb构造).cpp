#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
void solve() {
	int n;
	cin>>n;
	int a[n],b[n+1];
	for(int x=1;x<n;x++)cin>>a[x];//正常读入n-1
	b[1]=a[1],b[n]=a[n-1];//两边初始化，
	for(int x=2;x<=n-1;x++){
		b[x]=min(a[x],a[x-1]);//现在缺n-2项
		//每一个x代表筛选这个下标位置的b[]值；
		//这里设x为下标的为（x-1）x,当x=2,为12，3为23；
		//12向1看齐，23向12看齐以此类推；
		//显然b[1]=a[1],b12必定<=b1即a1,b12必定<=a2,此时b2位置正确满足，即max(b1,b12)=a[1]；
		//b23必定<=a2,a3，b12<=a1,a2,如果三者间a2最大，应该是无解的;
		//如a1<a2>a3,转为b1,b2,b3,b4::max(b1,b2)=a1,max(b2,b3)=a2,max(b3,b4)=a3;
		//这样不做论证，可假设，b1,b2等的相对大小，分配谁是a1,往后推；
		//结果是不可能出现这种情况；
		//这里考虑中间或最小，若最小两者都为a2,a2,那么max(b12,b23)=a2,满足;
		//中间大小，两者一定一个为a2,一个小于a2,取max还是a2，以此类推之后的；
		//末尾情况与首情况无异；
	}
	for(int x=1;x<=n;x++){
		cout<<b[x];	
		if(x!=n)cout<<' ';
	}
	cout<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
