#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e5+10,INF=0x3f3f3f3f;
using namespace std;
long long int n,a[N],b[N],c[N],cc[N],aa[N];//不开long long 见祖宗；
long long ans=0;
void solve() {
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	for(int x=1;x<=n;x++){
		cin>>b[x];
	}
	for(int x=1;x<=n;x++){
		cin>>c[x];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	//排序是必须的；
	//由a<b<c,则可找到每一个b，查出多少个满足的a和满足的c，加上它们的乘积即可;
	//二分查找，否则超时；
	for(int x=1;x<=n;x++){
		int l=1,r=n,mid,as=0;
		while(l<=r){
			mid=(l+r)/2;
			if(a[mid]<b[x]){
				as=mid;
				l=mid+1;
			}
			else {
				r=mid-1;
			}
		}
		aa[x]=as;
	}
	for(int x=1;x<=n;x++){
		int l=1,r=n,mid,as=0;
		while(l<=r){
			mid=(l+r)/2;
			if(c[mid]>b[x]){
				as=n-mid+1;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		cc[x]=as;
		ans+=cc[x]*aa[x];
	}
	cout<<ans<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
