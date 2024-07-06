#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 2e2+10,INF=0x3f3f3f3f;
using namespace std;
int n,res=0;
bool s[N],s1[N];
//这个sb题随便写的没想到能对，甚至我的代码比很多人的要短，离谱
void solve() {
	res=0;
	cin>>n;
	vector<int>as,as1;
	for(int x=1;x<=n;x++){
		char i;
		cin>>i;
		if(i=='W')s[x]=true,s1[x]=true;
		else s[x]=false,s1[x]=false;
		//化为bool型
	}	
	//以下没啥好说的，判断要不要改，就看和前面同不同
	//可能是由于从2开始改，1没顾及到，有些情况是需要改1的，所有若判-1
	//再改1，2，res+1，push(1)，顺一遍，看看行不行
	for(int x=2;x<=n-1;x++){
		if(s[x]!=s[x-1])s[x]=!s[x],s[x+1]=!s[x+1],res++,as.push_back(x);
	}
	if(s[n-1]==s[n]){
		cout<<res;
		if(res>0)cout<<endl;
		for(auto &it:as)cout<<it<<' ';
		cout<<endl;
	}
	else {
		res=1;
		s1[1]=!s1[1],s1[2]=!s1[2];
		as1.push_back(1);
		for(int x=2;x<=n-1;x++){
			if(s1[x]!=s1[x-1])s1[x]=!s1[x],s1[x+1]=!s1[x+1],res++,as1.push_back(x);
		}
		if(s1[n-1]==s1[n]){
			cout<<res;
			if(res>0)cout<<endl;
			for(auto &it:as1)cout<<it<<' ';
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
}
int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
