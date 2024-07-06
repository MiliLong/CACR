#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 3e5+10,INF=0x3f3f3f3f;
using namespace std;
int n,m,a[N],s[N],res=INT_MIN;
//找出长度不超过m的连续子序列，使得子序列中所有数的和最大
//思路：：对于区间的sum先求前缀和，一个区间等于a[r]-a[l-1],由于区间长度不超过m
//对于r一定的情况下，r-(l-1)最大为m，也就是(l-1)这个坐标范围其实相对于r是确定的，
//而我们要找到a[r]-a[l-1]最大的情况，又由于r确定a[r]确定，求区间最大，只需要找(l-1)坐标在
//允许范围内的最小值即可这里我们可以使用单调队列来维护，这里建议队列存着元素下标，比较时
//也不麻烦，有下标值就有了，维护一个单调递增序列从而维护最小值，序列长度小于等于m，窗口范围其实
//就是(r-m)->(r-1)即我们能减去元素的范围
//注意：：res要在存入新元素前更新，我们是先遍历到元素以其为a[r]的,存入单调栈后其就属于a[l-1]的
//范围内，sum可能会存在自己减去自己的情况，不符合。初始时要入栈一个元素0，代表着a[0]，因为对于初始项
//来说前面需要补充一个a[0],若没有,a[1]显然在很多情况下不会被加上，只会被减去,当然还有一种就是x从0开始
//这样就可以了，但是更新res时要满足条件x>0,因为若为其它元素和为负数还没a[0]大，会出现res=a[0]的情况
//但a[0]是我们自己加上的不能参与运算.
//最后一个问题是，为什么(if(q.front()<x-m)q.pop_front();)这一段放在最前，为什么不放在最后？
//举个例子：：0 1 2 3 4 5 6 7 ，0是我们加上的，假设m=4,我们的单调栈最长为4，当{0 1 2 3},我们该放4了
//这时4-4=0，这个回合始终不会发生0的出栈，之后我们加入4得{0 1 2 3 4}，下一回合，我们有一个长度为5的
//单调栈，这是不合情况的，所有要先出栈0，之后进行之后的操作.对于这种情况，我发出疑问为什么和之前做的
//单调队列的题放的位置不一样呢？想拉很长时间，其实就是个简单问题，由于刚才手动模拟发现，其实我们把小于改成小于等于即可
//其实和之前的一样mad，只是换一种做法人傻了
void solve() {
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		s[x]=a[x]+s[x-1];
	}
	deque<int>q;
	//q.push_back(0);
	for(int x=0;x<=n;x++){
		//(if(q.front()<x-m)q.pop_front();)
		if(x>0)res=max(res,s[x]-s[q.front()]);
		while(q.size()&&s[x]<=s[q.back()])
			q.pop_back();
		q.push_back(x);
		if(q.front()<=x-m)q.pop_front();
	}
	cout<<res<<endl;
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
