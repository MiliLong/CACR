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
//思路：：模拟建树的过程
//每次合法读入都相当于读入一个根节点，接下来进行建树操作，建左树，建右树
//通过对建树遍历树的具体代码（由前）的理解
//建树过程其实和遍历树的过程差别不大，而中序遍历就是在两个build间输出节点
//总结：：边建树边遍历
void build(){
	char c;
	cin>>c;
	if(c=='#')return;
	build();
	cout<<c<<' ';
	build();
}
void solve() {
	build();
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
