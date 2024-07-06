#include<bits/stdc++.h>
using namespace std;
int n, m, f[600], book[1000];
int find(int x) {
	int as = x;
	if (f[x] != x)as = find(f[x]);
	return as;
}
void merge(int a, int b) {
	int fa = find(a), fb = find(b);
	if (fa != fb)f[fa] = fb;
}
void init() {
	for (int x = 0; x < n; x++)f[x] = x;
}
void solve() {
	cin >> n >> m;
	vector<pair<int, int>>p;
	memset(book, 0, sizeof book);
	init();
	for (int x = 0; x < m; x++) {
		pair<int, int>md;
		cin >> md.first, cin >> md.second;
		merge(md.first, md.second);
		p.push_back(md);
	}
	int cout0 = 0, cout1 = 0;
	for (int x = 0; x < n; x++) {
		if (f[x] == x)cout0++;
	}
	int k;
	cin >> k;
	for (int x = 0; x < k; x++) {
		cout1 = 0;
		int i;
		cin >> i;
		book[i] = 1;
		init();
		for (auto &it : p) {
			if (book[it.first] != 1 && book[it.second] != 1) {
				merge(it.first, it.second);
			}
		}
		for (int x = 0; x < n; x++)if (f[x] == x && !book[x]) {
				cout1++;
			}
		if (cout1 > cout0) {
			cout << "Red Alert: City " << i << " is lost!" << endl;

		} else cout << "City " << i << " is lost." << endl;
		cout0 = cout1;
	}
	if (!cout0)cout << "Game Over.";
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
