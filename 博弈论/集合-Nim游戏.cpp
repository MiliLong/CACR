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
void solve(int T) {
	int n, k, res = 0; cin >> k;
	set<int>st;
	vector<int>f(10010, -1);
	for (int x = 0, i; x < k; x++) {
		cin >> i;
		st.insert(i);
	}
	auto sg = [&](auto && sg, int u)->int{
		if (f[u] != -1)return f[u];
		set<int>s;
		for (auto it : st) {
			if (it <= u)s.insert(sg(sg, u - it));
			else break;
		}
		int ans = 0;
		while (s.count(ans))ans++;
		return f[u] = ans;
	};
	//f[0] = 0;
	cin >> n;
	for (int x = 0, i; x < n; x++) {
		cin >> i;
		res ^= sg(sg, i);
	}
	cout << (res ? "Yes\n" : "No\n");
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
