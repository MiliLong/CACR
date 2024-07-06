#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define af1(x,a) for(int x=1;x<=a;x++)
#define af0(x,a) for(int x=0;x<a;x++)
#define ff first
#define ss second
#define pii pair<int ,int>
#define vvint vector<vector<int>>
const int N = 2e4 + 10, INF = 0x3f3f3f3f;
using namespace std;
int n, m, f[N];
//标准并查集板子题；
void init() {
	af1(x, n)f[x] = x;
}
int find(int i) {
	int as = i;
	if (f[i] != i)as = find(f[i]);
	return as;
}
void Union(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa != fb) {
		f[fa] = fb;
	}
}
void solve() {
	cin >> n >> m;
	init();
	af1(x, m) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	int q;
	cin >> q;
	af1(x, n)f[x] = find(x);
	while (q--) {
		int c, d;
		cin >> c >> d;
		if (f[c] == f[d])cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}//不要用endl了，每次清一遍缓冲区太慢了，卡死这题；
//cin，cout在数据量1e5以上开ios；
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
