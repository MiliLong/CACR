#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long
using ll = long long;//没开longlong见祖宗
const int N = 5e5 + 10, INF = 0x3f3f3f3f;
using namespace std;
int a[N], tree[N], r[N];
int n, ans = 0;
int lowbit(int x) {
	return x & (-x);
}
void add(int a, int b) {
	for (int x = a; x <= n; x += lowbit(x))tree[x] += b;
}
int sum(int a) {
	int res = 0;
	for (int x = a; x; x -= lowbit(x))res += tree[x];
	return res;
}
bool cmp(int x, int y) {
	return a[x] >= a[y]; //由于需要下标大的放前面所以>=以至于相等时也发生置换
	//也可不用stable_sort()::遇到相等的值不改变其相对位置
	//if(a[x]!=a[y])return a[x]>a[y];
	//return x>y;
	/*
	6
	5 4 2 1 1 1
	1 2 3 6 5 4
	*/
	//两种方法若前者不加=为1 2 3 4 5 6
	//后者不加return x>y;同理
	//目的都为将先出现的相同值放后，这样算前面的值的时就不会算入相同值
	//模拟一下
	//放6，111001前面3个
	//放5，111011前面3个
	//放4，111111前面3个
	//否则，1 2 3 4 5 6
	//放4，111100前面3个
	//放5，111110前面4个，多记录了
	//放6，111111前面5个，多记录了
}
void solve() {
	cin >> n;
	for (int x = 1; x <= n; x++) {
		cin >> a[x];
		r[x] = x;
	}
	stable_sort(r + 1, r + n + 1, cmp);
	//这一步中sort按照a[]的大小规则降序排列
	//r[]最初是存的每一处其的下标
	//按样例解释：：5>1,4>2,2>3,6>4,3>5,1>6
	//排序后为654321映射为412536
	//这里为了从大到小的输出下标通过1-n顺序的输出
	for (int x = 1; x <= n; x++)add(r[x], 1), ans += sum(r[x] - 1);
	cout << ans << endl;
}
/*
6
5 4 2 6 3 1
mad手动模拟一下方便理解
000000
000100 sum[3]=0
100100 sum[0]=0
110100 sum[1]=1
110110 sum[4]=3
111110 sum[2]=2
111111 sum[5]=5
从大到小放数，在其坐标位置+1，6在4位置先在4位置+1，此时找比6大的即sum[3],前面所以大的应都为1
接下来是5，前面无，接下来是4，此时前面1位置有一个5比它大,sum[1]=1...
最看最小的最后放，其值为1，位置在6，6前面都放满了，则sum[5]=5
总结：：按大小先放大的在相应位置，这样保证每一次放一个数，在之前放的都是比它大的，这些数可能
在前面，也可能在后面，通过sum可求这个数前面的比它大的数的个数（放了我们都+1了，没放就是0，所以sum操作就是个数）
先大后小也是为了统计是不计入比它小的在前面的数的个数
*/
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
