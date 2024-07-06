#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e7+10,INF=0x3f3f3f3f;
using namespace std;
int l,n,k,mid,a[N];
bool check(int m){
	bool ans=true;
	int s=0;//记录使用次数；
	int f=0;//记录前一个路标位置；
	for(int x=2;x<=n;x++){
		if(s>=k+1)break;//使用次数溢出；
		int dis=a[x]-f;//距离；
		if(dis<=m){
			//满足；
			f=a[x];
			//前一个信标换成这一个；
		}
		else {
			f+=m;
			//前一个信标+=m；
			x--;//还是评测这个路标
			s++;//加次数；
		}
	}
	if(s>k)return false;
	return ans;
}
void solve() {
	cin>>l>>n>>k;
	int le=0,ri=l,as=0;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	while(le<=ri){
		//mid=le+(ri-le)/2;
		mid=(ri+le)/2;
		if(check(mid)){
			as=mid;
			ri=mid-1;
		}
		else {
			le=mid+1;
		}
	}
	cout<<as;
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
