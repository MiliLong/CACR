#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
#define int long long
const int N = 2e5+10,INF=0x3f3f3f3f;
using namespace std;
int n,a[N],i,re;
//思路：：根据假设的合格石堆的前缀和算合格的区间和，与实际比较即可判断特殊石子所在区间
//通过二分一步步缩小区间
//cout.flush();题目要求，所有输出后加
void solve() {
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		a[x]+=a[x-1];
	}
	int l=1,r=n,mid,as=-1;
	while(l<=r){
		if(l==r){
			break;
		}
		//由于else操作未对r更改l<=r会超时,必须特判，也可改为l<r
		//这里便于个人理解就特判，即最后状态肯定来到这个点，此时l->r区间石子有问题
		//由于l=r,显然之后输出r即可
		//若改为l<r,那么最后l<r,后成立l++,其实也一样
		mid=(l+r)/2;
		int len=mid-l+1,sum=a[mid]-a[l-1];
		cout<<"? "<<len;
		cout.flush();
		for(int x=l;x<=mid;x++)cout<<' '<<x;
		cout<<endl;
		cout.flush();
		cin>>re;
		if(re==sum){
			l=mid+1;
		}
		else {
			r=mid;
		}
	}
	cout<<"! "<<l/*r*/<<endl;
	cout.flush();
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
