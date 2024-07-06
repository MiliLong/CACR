#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long
using ll = long long;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
using namespace std;
int m = 3000;
void fill_0(vector<int>&a) {
	while (m - a.size())a.push_back(0);
}//前驱填0
vector<int> add(vector<int>a, int b) {
	vector<int>ans;
	for (int x = 0; x < b; x++)ans.push_back(0);
	for (int x = 0; x < m - b; x++) {
		ans.push_back(a[x]);
	}
	return ans;
}//后驱填0
vector<int> sum(vector<int>a, vector<int>b) {
	vector<int>ans;
	int len = m;
	int up = 0;
	for (int x = 0; x < len; x++) {
		int s = a[x] + b[x] + up;
		ans.push_back(s % 10);
		up = s / 10;
	}
	return ans;
}//高精求和
vector<int> mul_(vector<int>a, int b) {
	vector<int>ans;
	int len = m;
	int up = 0;
	for (int x = 0; x < len; x++) {
		int s = a[x] * b + up;
		ans.push_back(s % 10);
		up = s / 10;
	}
	return ans;
}//高精乘个位
vector<int> mul(vector<int>a, vector<int>b) {
	vector<int>ans(m);
	fill_0(ans);
	for (int x = 0; x < m; x++) {
		vector<int>md = mul_(a, b[x]);
		ans = sum(ans, add(md, x));
	}
	return ans;
}//高精相乘
void solve() {
	string aa, bb;
	cin >> aa >> bb;
	vector<int>a, b;
	for (int x = 0; x < max(aa.size(), bb.size()); x++) {
		if (x < aa.size()) {
			a.push_back(aa[x] - '0');
		}
		if (x < bb.size()) {
			b.push_back(bb[x] - '0');
		}
	}
	reverse(all(a)), reverse(all(b));
	fill_0(a), fill_0(b);
	vector<int>ans = mul(a, b);
	bool is = true;
	for (int x = ans.size() - 1; x >= 0; x--) {
		if (ans[x] == 0 && is) {
			if (x == 0)cout << 0;
			continue;
		}
		else cout << ans[x], is = false;
	}
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
