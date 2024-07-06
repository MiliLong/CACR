#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
//#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
int da[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool is_y(int y){
	return ((y%4==0&&y%100!=0)||y%400==0);
}
int get_day(int n){
	int y=n/10000,m=n%10000/100,d=n%100;
	if(is_y(y))da[2]=29;
	else da[2]=28;
	while(m--)d+=da[m];
	while(y--)d+=(is_y(y)?366:365);
	return d;
}
void solve() {
	int a,b;
	while(cin>>a>>b){
		cout<<abs(get_day(a)-get_day(b))+1<<'\n';
	}
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	//cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
