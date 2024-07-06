#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 5e3+10,INF=0x3f3f3f3f;
using namespace std;
int s[N][N],n,r;
//s[x][y]代表横坐标纵坐标分别小于x,y的项的总和
void solve() {
	//x,y范围0->5000便于计算，防止数组越界全部++，1->5001
	cin>>n>>r;
	r=min(5001,r);//大了也没用，直接全部覆盖，5001
	for(int x=1;x<=n;x++){
		int a,b,w;
		cin>>a>>b>>w;
		a++,b++;
		s[a][b]+=w;
	}
	for(int x=1;x<=5001;x++){
		for(int y=1;y<=5001;y++){
		s[x][y]+=s[x-1][y]+s[x][y-1]-s[x-1][y-1];//求二维数组的前缀和
		}
	}
	int ans=0;
	for(int x=r;x<=5001;x++){
		for(int y=r;y<=5001;y++){
			ans=max(ans,s[x][y]-s[x-r][y]-s[x][y-r]+s[x-r][y-r]);//求这一块的sum
		}
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
/*		画图就懂了，区块的sum同理
		1111	求前缀和
		1111
		1111
		0000
		————
		1110
		1110
		1110
		1110
		————
		1111
		1111
		1111
		1111
		等于前两图加
		减去
		1110
		1110
		1110
		0000
		加上
		0000
		0000
		0000
		0001
*/
