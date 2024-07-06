#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define int long long//sb long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//题意：：取1->n-1的某些数的乘积%n=1，满足数的数量最大
//核心：：取该区间和n互质的数，假如不互质，我们设选中的数中有一个数和n的gcd为x,x!=1
//最终答案也一定是x的倍数，相乘的元素的一个约数是总的约数，那么假设最终结果为sum=a*x,n=b*x;
//sum%n运算下答案一定是x的倍数，其实就是a%b*x,这玩意永远成不了1
//接下来的问题是，如果一直sum=sum*x%n;sum最后等于1还好，如果不等于1呢？
//首先我们知道sum与n互质，sum肯定<n,那么sum肯定是前面的一个和n互质的数，我们减去这个数
//相当于sum/sum=1,显然1%n=1,证毕，结果是只需要去除与sum重复的值即可
int gcd(int a,int b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
void solve() {
	int n;
	cin>>n;
	int sum=1;
	vector<int>as;
	for(int x=1;x<n;x++){
		if(gcd(n,x)==1){
			sum=sum*x%n;
			as.push_back(x);
		}
	}
	if(sum!=1){
		cout<<as.size()-1<<endl;
		as.erase(find(as.begin(),as.end(),sum));
	}
	else cout<<as.size()<<endl;
	for(vector<int>::iterator it=as.begin();it!=as.end();++it){
		if(it!=as.begin())cout<<' ';
		cout<<*it;
	}
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
