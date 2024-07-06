#include<bits/stdc++.h>
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define PII pair<int ,int>
const int N = 1e9+10;
using namespace std;
//进制转换用这个秦九绍算法；
//用哈希表存可能出现的数字，如果出现两次就cout；
//还有写特殊情况需要特判，当然应该可以通过代码直接涵盖，不过特判首字符是不是0是需要的；
int change(string s,int z){
	int len=s.size();
	int as=s[0]-'0';
	if(z==2)for(int x=1;x<len;x++){
		as=(as*2+s[x]-'0');
	}
	else if(z==3)for(int x=1;x<len;x++){
		as=(as*3+s[x]-'0');
	}
	return as;
} 
void solve() {
	string s1,s2;
	cin>>s1;
	cin.get();
	cin>>s2;
	map<int,bool>hash;
	if(s1[0]=='0'){
		s1[0]='1';
		cout<<change(s1,2)<<endl;
		return;
	}
	if(s2[0]=='0'){
		s2[0]='1';
		cout<<change(s2,3)<<endl;
		return;
	}
	if(s1.size()==1){
	cout<<!(s1[0]-'0');
	return;
	}
	for(int x=0;x<s1.size();x++){
		string md=s1;
		md[x]=!(md[x]-'0')+'0';
		if(x==0&&md[x]=='0')continue;
		int re=change(md,2);
		hash[re]=true;
	}
	if(s2.size()==1){
	for(int x=0;x<=2;x++){
		if(s2[0]-'0'!=x){
			if(hash.find(x)!=hash.end()){
			cout<<x<<endl;
			return ;
			}
		}
	}
	return;
	}
	for(int x=0;x<s2.size();x++){
		for(int z=0;z<=2;z++){
			string md=s2;
			if(md[x]==z+'0')continue;
			md[x]=z+'0';
			if(x==0&&s2[x]=='0')continue;
			int re=change(md,3);
			if(hash.find(re)!=hash.end()){
			cout<<re<<endl;
			return ;
			}
			else {
			hash[re]=true;
			}
		}
	}
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
