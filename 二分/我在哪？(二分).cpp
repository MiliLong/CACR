#include<bits/stdc++.h>
//a.sunstr(初始位置，截取对长)；
#define de(a) cout<<#a<<'='<<a<<"\n"
#define deg(a) cout<<#a<<'='<<a<<' '
using namespace std;
string s;
int n;
bool check(int x){
	map<string,bool>m;
	for(int xx=0;xx<=s.size()-x;xx++){
		if(m.find(s.substr(xx,x))!=m.end()){
			return false;
		}
		else {
			m[s.substr(xx,x)]=true;
		}
	}
	return true;
}
void solve() {
	cin >> n;
	cin >> s;
	int mid,l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
		 	r=mid-1	;
		}
		else {
			l=mid+1;
		}
	}
	cout<<l<<endl;
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
