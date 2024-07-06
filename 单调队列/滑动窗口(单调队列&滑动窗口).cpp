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
int n,k,a[N];
deque<int>q;//双端队列
//单调队列：：可以动态的维护区间最大最小值，需要维护的属性放队列头，维护最大，降序排列
//维护最小，升序排列，每次输入新值按顺序插入队列，也必须插入队列，任何与影响单调的其它元素都需出栈，最后新元素在队列尾部
//举例：：5 6 7 1 2 ，若维护最小动态区间长度为2，元素1{5}，2{5，6}，3{5，6，7}->由于长度为2，5出栈
//，4{1}，5{1，2}，过程中动态维护队列长度<=规定长度，若大于就需进行出栈操作，即栈头等于a[x-k]
//如下标 1 2 3，区间长度为2，读到3此时{1，2，3}3已经入栈，判断头是否出栈，front()==3-2=1即判断出栈，即q.front()==a[x-k]
//当读入坐标>=k次后开始输出队头
//为什么队头是维护的属性，因为我们规定队头存属性，队尾更新元素，也可用队尾但此时我们需要从队头处进行常规的同上的尾部出栈操作，元素顺序也会相反
//还有为什么，我们尾部出栈，头部只出栈不在区间的元素时，若升序，则是头部维护最小值，如果我们取队尾不就省事取最大值了吗？
//答案是no，这样的认识是错误的，若原来的数组为1 2 3 4 0，其在4元素读入时队列{1 2 3 4}维护的是最小值，当然我们假定区间长度为4吧，
//这时候我们加入新元素大小为0，按规定队列元素应清空，新队列{0}，但我们的区间为，此时我们区间的最大值是4，但此时队尾为0
//所以这种想法行不通
void solve() {
	cin>>n>>k;
	int e=1;
	for(int x=1;x<=n;x++)cin>>a[x];
	for(int x=1;x<=n;x++){
		while(q.size()&&q.back()>a[x])q.pop_back();
		q.push_back(a[x]);
		if(x-k>=1&&q.front()==a[x-k])q.pop_front();
		if(x>=k)cout<<q.front()<<' ';
	}
	cout<<endl;
	q.clear();
	for(int x=1;x<=n;x++){
		while(q.size()&&q.back()<a[x])q.pop_back();
		q.push_back(a[x]);
		if(x-k>=1&&q.front()==a[x-k])q.pop_front();
		if(x>=k)cout<<q.front()<<' ';
	}
	cout<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;；
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
