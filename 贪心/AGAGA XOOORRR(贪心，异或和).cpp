#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
//#define int long long 
using ll = long long;
const int N = 2e3+10,INF=0x3f3f3f3f;
using namespace std;
//异或和即数二进制表示后每一位相同为0相异为1
//异或和具有结合律，若两数异或和为0，那么两数相等
//有此基础，我们对所有求异或和，若结果为0，那么倒数第二步肯定出现两数相等
//若不为0，我们寻找挨个异或和为i的情况，统计个数，若>2显然成立，显然肯定为奇数
//偶数情况在上，奇数也为偶数加1，偶数异或和为0，异或和i等于i，显然成立
//反之小于二，组不成偶数，奇数也组不了，因为区间凑不出来另一个i
int n,a[N];
void solve() {
	cin>>n;
	int i=0;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		i=i^a[x];
	}
	if(i==0)cout<<"YES";
	else {
		int j=0;
		int s=0;
		for(int x=1;x<=n;x++){
			j=j^a[x];
			if(j==i)s++,j=0;
		}
		if(s>=2)cout<<"YES";
		else cout<<"NO";
	}
	cout<<endl;
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
