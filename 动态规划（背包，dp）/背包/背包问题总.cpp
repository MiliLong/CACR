#include<bits/stdc++.h>
using namespace std;
int t, n;
const int N = 0x3f3f3f;
int ti[N], pi[N], ci[N], f[N];
//vi为重量，wi为价值； 
void zero_one_pack(int vi, int wi) {
	for (int j = t; j >= vi; j--) {
		f[j] = max(f[j], f[j - vi] + wi);
	}
}
void complete_pack (int vi, int wi) {
	for (int j = vi; j <= t; j++) {
		f[j] = max(f[j], f[j - vi] + wi);
	}
}
void multiple_pack(int vi, int wi, int si) {
	if(si==0){
		complete_pack(vi, wi);
	}
	if (vi * si >= t) {
		complete_pack(vi, wi);
	} else {
		int k = 1;
		while (k < si) {
			zero_one_pack(k * vi, k * wi);
			si -= k;
			k *= 2;
		}
		if (si > 0) {
			zero_one_pack(si * vi, si * wi);
		}
	}
}
int main () {
	int h1, m1, h2, m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	t = h2 * 60 + m2 - h1 * 60 - m1;
	cin >> n;
	for (int x = 1; x <= n; x++) {
		cin >> ti[x] >> ci[x] >> pi[x];
		multiple_pack(ti[x], ci[x], pi[x]);
	}
	cout << f[t] << endl;
	return 0;
}
