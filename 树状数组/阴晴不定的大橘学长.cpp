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
#define int long long
#define yes "YES\n"
#define no "NO\n";
using LL = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;
int n, k, res = 0;
vector<int>tree(N);
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
void solve(int T) {
	cin >> n >> k;
	vector<PII>a(n + 1);
	vector<int>b(n + 1, 0), pos(n + 1, 0);
	for (int x = 1, i; x <= n; x++) {
		cin >> b[x];
		b[x] += b[x - 1];
		if (b[x] >= k)res++;
	}
	for (int x = 1; x <= n; x++)a[x] = {b[x], x};
	sort(a.begin() + 1, a.end());
	for (int x = 1; x <= n; x++) {
		pos[a[x].ss] = x;
	}

	for (int x = 1; x <= n; x++) {
		res += sum(pos[x]);
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (a[mid].ff - b[x] >= k)r = mid;
			else l = mid + 1;
		}
		if (a[l].ff - b[x] >= k)add(l, 1);
	}
	cout << res << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve(T);
	}
	return 0;
}
