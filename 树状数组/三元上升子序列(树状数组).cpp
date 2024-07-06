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
const int N = 3e4 + 10, INF = 0x3f3f3f3f;
using namespace std;
int a[N], tree[N], r[N], tree1[N], r1[N], as[N], a1[N];
int n, ans = 0;
int lowbit(int x) {
	return x & (-x);
}
void add(int *tree, int a, int b) {
	for (int x = a; x <= n; x += lowbit(x))tree[x] += b;
}
int sum(int *tree, int a) {
	int res = 0;
	for (int x = a; x; x -= lowbit(x))res += tree[x];
	return res;
}
bool cmp(int x, int y) {
	return a[x] <= a[y];
}
bool cmp1(int x, int y) {
	return a1[x] >= a1[y];
}
void solve() {
	cin >> n;
	for (int x = 1; x <= n; x++) {
		cin >> a[x]; //正
		a1[n - x + 1] = a[x]; //逆
		r[x] = x; //正
		r1[x] = x; //逆
	}
	stable_sort(r + 1, r + n + 1, cmp);
	stable_sort(r1 + 1, r1 + n + 1, cmp1);
	//思路就是找每一个位置前面比它小的，后面比它大的
	//小的就是升序离散化后，二元逆序对方法就行,存入该坐标数组中
	//大的相当于从后往前，直接把数组逆序，降序离散化
	//由于逆升序后同一数的下标不同但和为n+1
	//然后就相同方法但这一步循环求ans，ans+=as[n-r1[x]+1]*sum(tree1,r1[x]-1)即可
	for (int x = 1; x <= n; x++)add(tree, r[x], 1), as[r[x]] = sum(tree, r[x] - 1);
	for (int x = 1; x <= n; x++)add(tree1, r1[x], 1), ans += as[n - r1[x] + 1] * sum(tree1, r1[x] - 1);
	cout << ans << endl;
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
