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
int dx[4] = { -1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using namespace std;

int n, m, g[27][27];

void solve() {

	while (cin >> n >> m) {
		if (n <= 0 || m <= 0)
			break;
		for (int x = 0; x < 27; x++)
			for (int y = 0; y < 27; y++)
				g[x][y] = 0;

		int cnt = 0;
		bool No = false, Nono = false, ok = false;;
		while (m--) {
			char u, v, md; cin >> u >> md >> v;

			if (ok || No)
				continue;
			++cnt; Nono = false;
			g[u - 'A'][v - 'A'] = 1;

			for (int k = 0; k < n; k++)
				for (int x = 0; x < n; x++)
					for (int y = 0; y < n; y++)
						g[x][y] |= g[x][k] && g[k][y];

			for (int x = 0; x < n; x++)
				if (g[x][x])
					No = true;

			if (No)
				continue;

			for (int x = 0; x < n; x++)
				for (int y = 0; y < n; y++)
					if ((!(g[x][y]^g[y][x])) && x != y)Nono = true;

			if (Nono)
				continue;

			ok = true;
			vector<PII>in(n, {0, 0});

			for (int x = 0; x < n; x++) {
				auto &[_in, id] = in[x];
				id = x;
				for (int y = 0; y < n; y++)
					if (g[x][y])_in++;
			}

			sort(all(in), [&](PII a, PII b) {
				return a.ff > b.ff;
			});

			cout << "Sorted sequence determined after " << cnt << " relations: ";

			for (auto [_in, id] : in)
				cout << char('A' + id);

			cout << ".\n";
		}

		if (ok)
			continue;

		if (No)
		{
			cout << "Inconsistency found after " << cnt << " relations.\n";
			continue;
		}

		if (Nono)
		{
			cout << "Sorted sequence cannot be determined.\n";
			continue;
		}

	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T, cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
