#include<bits/stdc++.h>
//#define int long long
#define ff first
#define ss second
using namespace std;
char pd(string s) {
	bool is0 = false, is1 = false;
	for (int x = 0; x < s.size(); x++) {
		if (s[x] == '0')is0 = true;
		else is1 = true;
	}
	if (is1 && is0)return 'F';
	else if (is1)return 'I';
	else return 'B';
}
pair<string, string> fen(string s) {
	string s1, s2;
	s1=s.substr(0,s.size()/2);//0往后s.size()/2个
	s2=s.substr(s.size()/2);//s.size()/2开始往后所有
	return {s1, s2};
}
void dfs(string s) {
	if (s.size() == 1) {
		cout << pd(s);
		return;
	}
	auto [s1,s2]=fen(s);//结构化绑定
	dfs(s1);
	dfs(s2);
	//模拟建树，边输出
	cout << pd(s);
	//后续遍历
}
void solve () {
	int n;
	cin >> n;
	string i;
	cin >> i;
	dfs(i);
}
signed main () {
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}