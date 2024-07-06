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
void solve() {
	int n; cin >> n;
	vector<PII>eg, u;
	for (int x = 0; x < n; x++) {
		int l, r, a, b; cin >> l >> r >> a >> b;
		eg.push_back({l, b});
	}

	sort(all(eg));

	for (auto [l, r] : eg) {
		if (u.empty())u.push_back({l, r});
		else {
			auto &[fl, fr] = u.back();
			if (l > fr)u.push_back({l, r});
			else {
				fr = max(fr, r);
			}
		}
	}

	int len = u.size();
	int q; cin >> q;
	while (q--) {
		int p; cin >> p;
		int l = 0, r = len - 1;
		while (l < r) {
			int mid = (l + r) >> 1;

			auto [ll, rr] = u[mid];
			if (rr >= p)r = mid;
			else l = mid + 1;
		}
		if (p <= u[r].ss && p >= u[r].ff) {
			cout << u[r].ss << ' ';
		}

		else cout << p << ' ';
	}
	cout << '\n';
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
