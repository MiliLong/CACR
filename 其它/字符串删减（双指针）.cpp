#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define PII pair<int ,int>
const int N = 1e6+10;
using namespace std;
//没什么可说的就是简单的双指针；
void solve() {
	int n;
	string s;
	cin>>n>>s;
	int l=0,r=l+1,as=0;
	for(l,r;r<n;){
		int m=1;
		while(s[l]=='x'&&s[l]==s[r]){
			m++;
			r++;
		}	
		if(m>=3){
			as+=(m-2);
		}
		l=r;
		r++;
	}
	cout<<as<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
