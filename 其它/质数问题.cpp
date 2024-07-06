#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define af1(x,a) for(int x=1;x<=a;x++)
#define af0(x,a) for(int x=0;x<a;x++)
#define af(x,z,a) for(int x=z;x a;x++)
#define ff first
#define ss second
#define pii pair<int ,int>
#define vvint vector<vector<int>>
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
int a[2007],s=0,b[5007];
bool mp[5000];//是质数就存表，防止重复check浪费时间；
bool check(int m){
	for(int x=2;x<=sqrt(m);x++){
		if(m%x==0)return false;
	}
	return true;
}//检测是否为质数；
void shai(){
	for(int x=2;x<=2000;x++){
		if(check(x)){
			mp[x]=true;
			a[s]=x;
			s++;
		}
	}
}//筛选2000内的质数；
void solve() {
	int n,k;
	cin>>n>>k;
	if(b[n]>=k)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	memset(mp,false,sizeof mp);
	shai();
	memset(b,0,sizeof b);
	af0(x,s-1){
	if(mp[a[x]+a[x+1]+1]){
		b[a[x]+a[x+1]+1]=1;
	}
	}
	af1(x,2008){
		b[x]+=b[x-1];
	}//差分可求各个位置前的满足情况的质数数量；
	while (t--) {
		solve();
	}
	return 0;
}
