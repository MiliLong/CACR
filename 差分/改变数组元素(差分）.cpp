#include<bits/stdc++.h>
using namespace std;
//差分，可在一段区间内加一个数，标准形式a[l]+=c,a[r+1]-=c,通过对之后a数组求前缀和
//置换每处的a[]之后可加上原本数组，即可在线性内进行区间加算；
//即原本a[]={0,0,0,0,0,0},接下来对下标为1，到3的项加一个数i，a[]={0,i,0,0,-i,0}
//之后对a[]求前缀和a[]={0,i,i,i,0,0},之后和原数组相加即可，通过求前缀和的步骤
//从下标为1开始往后每一步都更新为i，截止于3+1=4处把i消掉，之后就不会更新了；
void solve() {
	int n;
	cin>>n;
	int a[n+1],b[n+2];
	memset(b,0,sizeof b);
	for(int x=1;x<=n;x++){
    cin>>a[x];
		a[x]=min(a[x],x);
		int l=x-a[x]+1,r=x;	b[l]++,b[r+1]--;
	}
	for(int x=1;x<=n;x++){
		b[x]+=b[x-1];
		a[x]+=b[x];
	}
	for(int x=1;x<=n;x++){
		cout<<!!a[x]<<' ';//！！可将数转换为01，正则1，0则0；
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