#include<bits/stdc++.h>
//#pragma GCC optimize (1)
//#pragma GCC optimize (2)
//#pragma GCC optimize (3)
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
//#define int long long
#define yes "YES\n"
#define no "NO\n";
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
void solve() {
	vector<int>a(N, 0), tree(N, 0);
	auto lowbit = [](int x) {return x & (-x);};
	auto add = [&](int i, int j) {
		for (int x = i; x <= n; x += lowbit(x))tree[x] += j;
	};
	auto sum = [&](int i)->int{
		int res_ = 0;
		for (int x = i; x; x -= lowbit(x))res_ += tree[x];
		return res_;
	};
	//功能：：单点加值，区间求和
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
