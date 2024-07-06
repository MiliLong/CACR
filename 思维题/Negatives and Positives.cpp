#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int,int>
#define int long long 
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//0无条件让一个负数变正，两个负数相消变正，多次分类讨论，特判绝对值最小的负数是否需要与最小的正数互换符号
void solve() {
	int n,zero=0;cin>>n;
	int a[n+1];
	vector<int>f,z;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		if(a[x]>0)z.emplace_back(a[x]);
		else if(a[x]==0)zero++;
		else f.emplace_back(a[x]);
	}
	sort(all(f),greater<int>()),sort(all(z));
	int sum=0;
	if(zero>=1||!(f.size()&1)){
		;
	}
	else if(f.size()){
		if(z.size()&&abs(f[0])>z[0]){
			z[0]*=-1;
			//f[0]*=-1;
		}
		else if(f.size()&1)f[0]*=-1;
	}
	for(auto u:f)sum+=u*-1;
	for(auto u:z)sum+=u;
	cout<<sum<<'\n';
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
/*
for(auto &u:f){
		if(zero)break;
		u*=-1;
		zero--;
	}
	int sf=f.size(),sz=z.size();
	sort(all(f));
	int l=0,r=0;
	for(int x=0;x<min(sf,sz);x++){
		if(f[l]>0)break;
		if(abs(f[l])>abs(z[r])){
			f[l]*=-1;
			z[r]*=-1;
			l++,r++;
		}
		else l++;
	}
	int sum=0;
	for(auto u:f)sum+=u;
	for(auto u:z)sum+=u;*/