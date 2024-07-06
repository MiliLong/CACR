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
map<string, int>pos;
class SPFA {
public:
	int n;
	vector<vector<PII>>eg;
	vector<double>dist;
	vector<int>cnt, vis;
	bool spfa(double u) {
		dist.insert(dist.begin(), n + 1, 0.0);
		cnt.insert(cnt.begin(), n + 1, 0);
		vis.insert(vis.begin(), n + 1, 0);
		queue<int>que;
		for (int x = 1; x <= n; x++) {
			que.push(x);
			vis[x] = true;
		}
		int count = 0;
		while (que.size()) {
			int t = que.front(); que.pop();
			vis[t] = false;

			for (auto [it, w] : eg[t]) {
				if (dist[it] < dist[t] + w - u) {
					dist[it] = dist[t] + w - u;
					cnt[it] = cnt[t] + 1;
					if (++count >= 4 * n)return true;
					if (cnt[it] >= n)return true;
					if (!vis[it]) {
						vis[it] = true;
						que.push(it);
					}

				}
			}
		}
		return false;
	}

	SPFA(int n): n(n), dist(n + 1), cnt(n + 1), vis(n + 1), eg(n + 1) {};
};
void solve(int T) {
	int n = T;

	SPFA s(26 * 26);

	for (int x = 0; x < n; x++) {
		string str; cin >> str;
		if (str.size() >= 2) {
			int u = pos[str.substr(0, 2)], v = pos[str.substr(str.size() - 2, 2)];
			s.eg[u].push_back({v, str.size()});
		}
	}

	if (!s.spfa(0)) {
		cout << "No solution\n";
		return;
	}
	double l = 0, r = 1010;
	while (r - l >= 1e-6) {
		double mid = (l + r) / 2;
		if (s.spfa(mid))l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(6) << l << '\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1, cnt = 0;
	for (int x = 0; x < 26; x++) {
		for (int y = 0; y < 26; y++) {
			string str ;
			str.push_back(('a' + x));
			str.push_back(('a' + y));
			pos[str] = ++cnt;
		}
	}
	//cin >> T, cin.get();
	while (cin >> T) {
		if (!T)break;
		solve(T);
	}
	return 0;
}
