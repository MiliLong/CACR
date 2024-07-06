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
long long int k,x;
long long sum(long long int z){
	if(z<=k)return (z+1)*z/2;//<=k层的表情和；
	else {
		return 2*(k+1)*k/2-k-sum(2*k-z-1);//大于k层相当于2k-1层减去2*k-z-1层；
	}
}
bool check(long long m){
	if(sum(m)>x&&sum(m-1)>=x/*满足该项违反，前一项违反或者前一项刚好等于x以至于后一项被禁止*/)return false;
	else return true;
}
void solve() {
	cin>>k>>x;
	long long int l=1,r=2*k-1,mid,as=1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			as=mid;
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	cout<<as<<endl;
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
