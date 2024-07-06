#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long 
using ll = long long;
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,a,b,c[N][N],o1[N][N],o2[N][N],ans=0;
//思路：：横着弄一次单调队列，对于每个存进数组，纵着弄一次单调队列，对于每个存进数组
//举个例子：：
//3 3 2 2		
//1 2 3
//6 5 4
//7 8 9
//先取最大
//横着做一次得矩阵
//2 3
//6 5
//8 9
//代表着6块不同的横向长度为b=2的区间的最大值
//对新矩阵纵着做一次得矩阵
//6 5
//8 9
//同样方法做一次取最小，得到同样大小的矩阵，ans动态叠加同位置乘积取mod
//详细讲解，假如我们的窗口移到
//2 3
//5 4
//要取得该窗口的最大最小，假如说最大，先取行最大
//得3
//  5，再取列最大得5，该操作就能取块最大，最小同理
//一个n*m得矩阵，窗口为a*b，我们能得到(n-a+1)*(m-b+1)个区块
//该方法最后得到一个(n-a+1)*(m-b+1)的矩阵，每一个位置就是一个区块的最值
//总结：：纯纯板子题，也就相比下二维维护最值特殊点，代码粘贴4次，就改了点小地方，美滋滋
void solve() {
	cin>>n>>m>>a>>b;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++)cin>>c[x][y];
	}
	int h=n-a+1,z=m-b+1; 
	deque<int>q;
	for(int x=1;x<=n;x++){
		int f=0;
		for(int y=1;y<=m;y++){
			while(q.size()&&q.back()<c[x][y])
				q.pop_back();
			q.push_back(c[x][y]);
			if(y-b>=1&&q.front()==c[x][y-b])q.pop_front();
			if(y-b>=0){
				f++;
				o1[x][f]=q.front();
			}
		}
		q.clear();
	}
	for(int y=1;y<=m-b+1;y++){
		int f=0;
		for(int x=1;x<=n;x++){
			while(q.size()&&q.back()<o1[x][y])
				q.pop_back();
			q.push_back(o1[x][y]);
			if(x-a>=1&&q.front()==o1[x-a][y])q.pop_front();
			if(x-a>=0){
				f++;
				o2[f][y]=q.front();
			}
		}
		q.clear();
	}
	for(int x=1;x<=n;x++){
		int f=0;
		for(int y=1;y<=m;y++){
			while(q.size()&&q.back()>c[x][y])
				q.pop_back();
			q.push_back(c[x][y]);
			if(y-b>=1&&q.front()==c[x][y-b])q.pop_front();
			if(y-b>=0){
				f++;
				o1[x][f]=q.front();
			}
		}
		q.clear();
	}
	for(int y=1;y<=m-b+1;y++){
		int f=0;
		for(int x=1;x<=n;x++){
			while(q.size()&&q.back()>o1[x][y])
				q.pop_back();
			q.push_back(o1[x][y]);
			if(x-a>=1&&q.front()==o1[x-a][y])q.pop_front();
			if(x-a>=0){
				f++;
				o2[f][y]*=q.front();
				ans+=o2[f][y];
				ans%=998244353;
			}
		}
		q.clear();
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
