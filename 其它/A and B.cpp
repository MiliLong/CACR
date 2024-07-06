#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//思路：：
//假设答案为res
//(res+1)*res/2为我们整体加上的值，最后a,b相等,代表最后a=b=(a+b+(res+1)*res/2)/2
//既然我们假设res为答案，那么显然res可以拆为q+m(q和m都是1->res间元素自由组合相加)
//a    b
//q    m
//a+q=b+m=(a+b+(res+1)*res/2)/2
//设c=abs(a-b)
//假设a小于b，则
//a    b
//m+c  m
//a+m+c=b+m=(a+b+(res+1)*res/2)/2
//a+m+c+b+m=a+b+(res+1)*res/2
//2m+c=(res+1)*res/2
//考虑c已知，2m是偶数，我们可以枚举res从0开始，寻找满足本式的res即为答案，设sum=(x+1)*x/2
//(sum-c)%2==0,其次我们要设定sum>=c，因为我们加上的数至少要与c抵消，这样才有a=b的可能
int a,b;
void solve() {
	cin>>a>>b;
	int c=abs(a-b);
	int res=0;
	for(int x=0;;x++){
		int sum=(x+1)*x/2;
		if((sum-c)%2==0&&sum>=c){
			res=x;
			break;
		}
	}
	cout<<res<<endl;
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
