#include<bits/stdc++.h>
using namespace std;
int a[31][31], as = 0x3f3f3f3f, book[24];
int n;
int dfs(int d, int s) {
	if (d >= n) {
		if (s < as)as = s;
		return 0;
	} 
		for (int x = 0; x < n; x++) {
			if (book[x] == 0 && s + a[d][x] < as) {
				book[x] = 1;
				dfs(d + 1, s + a[d][x]);
				book[x] = 0;
			}
		}
	
}
int main () {

	cin >> n;
	memset(book, 0, sizeof book);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> a[x][y];
		}
	}
	dfs(0, 0);
	cout << as;
	return 0;
}
