#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 5e5 + 10, INF = 0x3f3f3f3f;
using namespace std;
//功能：：单点加值，区间求和
//https://oiwiki.org/ds/fenwick/   学习树状数组
int a[N], tree[N];
int n, m;
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
void solve() {
	cin >> n >> m;
	for (int x = 1; x <= n; x++)cin >> a[x];
	for (int x = 1; x <= n; x++)add(x, a[x]);
	int to, a, b;
	while (m--) {
		cin >> to >> a >> b;
		if (to == 1) {
			add(a, b);
		}
		else {
			cout << sum(b) - sum(a - 1) << endl;
		}
	}
}
/*
C[1] = A[1];
C[2] = A[1] + A[2];
C[3] = A[3];
C[4] = A[1] + A[2] + A[3] + A[4];
C[5] = A[5];
C[6] = A[5] + A[6];
C[7] = A[7];
C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];
C数组表示tree[],A表示具体的数a[]
建树的板子好记，但不好理解，不过大概理解就行
比如add函数对某个值加数，假如是a[1]吧，相当于add操作是对c[1],c[2],c[4],c[8]进行加值
lowbit(x)(x&(-x))就是求所加坐标的位置的
C[7] + C[6] + C[4]为sum[7]前7项求和
sum函数通过lowbit找到要求和的坐标直接相加就是总和，不过只能求前多少项和
区间求和就是相减即可
*/
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
