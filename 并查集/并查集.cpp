#include<bits/stdc++.h>
using namespace std;
int n, m;
int p[510];
vector<pair<int, int>>path;
bool st[510];
int find(int i) {
	int as = p[i];
	if (p[i] != i)as = find(p[i]);
	return as;
}
void init() {
	for (int x = 0; x < n; x++)p[x] = x;
}
void merge( int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa != pb)p[pa] = pb;
}
void solve() {
	cin >> n >> m;
	init;
	for (int x = 0; x < m; x++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
		path.push_back({a, b});
	}
	int k;
	cin >> k;
	int cnt = 0, cnt1 = 0;
	for (int i = 0; i < n; i++)if (p[i] == i)cnt++;
	for (int x = 0; x < k; x++) {
		int ii;
		cin >> ii;
		cnt1 = 0;
		init();
		st[ii] = true;
		for (auto &it : path) {
			int a = it.first, b = it.second;

			if (st[a] || st[b])continue;
			merge(a, b);
		}
		for (int i = 0; i < n; i++)if (p[i] == i && !st[i])cnt1++;
		if (cnt1 > cnt) cout << "Red Alert: City " << ii << " is lost!\n";
		else cout << "City " << ii << " is lost.\n";
		cnt = cnt1;
	}
	if (!cnt)cout << "Game Over." << endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
