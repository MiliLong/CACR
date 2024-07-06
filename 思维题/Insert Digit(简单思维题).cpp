#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
void solve() {
	int l;
	cin>>l;
	char n;
	cin>>n;
	cin.get();
	string s;
	cin>>s;
	int as=-1;
	for(int x=0;x<l;x++){
		if(n>s[x]){
			//找到第一次n大于一位数的位置
			//为什么不是大于等于，n=4,54493不如544943
			as=x;
			break;
		}
	}
	if(as==-1)cout<<s<<n<<endl;
	else{
		for(int x=0;x<l;x++){
			if(x==as){
				cout<<n<<s[x];
				//在这个位置前一位输出n即可
			}
			else cout<<s[x];
			}
		cout<<endl; 
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
