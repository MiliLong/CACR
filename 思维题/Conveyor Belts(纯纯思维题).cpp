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
	int x1,y1,x2,y2,n;
	cin>>n>>x1>>y1>>x2>>y2;
	int c1x=min(abs(n-x1)+1,x1),c1y=min(abs(n-y1)+1,y1);//以此方法来分别求出x,y分别所在层；
	int c2x=min(abs(n-x2)+1,x2),c2y=min(abs(n-y2)+1,y2);
	int c1=min(c1x,c1y),c2=min(c2x,c2y);//该坐标的真是层应为x,y的min；
	//具体论证不详细描述，可假定x为主，那么用y来判断层数时，y>x时还是x层，y<x时为y层；
	//照着图好理解；
	cout<<abs(c1-c2)<<endl;//算层差；
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
