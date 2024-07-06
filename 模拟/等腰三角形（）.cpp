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
	int n;
	cin>>n;
	int end=n*2+2;
	int down=n*2-1;
	int md=down/2+1;
	string as="";
	for(int x=1;x<=end+1;x++){
		string m=to_string(x);//将数字转化为字符，便于之后处理；
		as+=m;
	}
	char ans[n+1][down+1];
	int use=md;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=use;y++){
			ans[x][y]='.';
		}
		use++;
	}
	use=md;
	int no=0;
	for(int x=1;x<n;x++){
		ans[x][use]=as[no];
		use--;
		no++;
	}
	for(int x=1;x<=down;x++){
		ans[n][x]=as[no];
		no++;
	}
	for(int x=n-1;x>=2;x--){
		ans[x][down-1]=as[no];
		no++;
		down--;
	}
	use=md;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=use;y++){
			cout<<ans[x][y];
		}
		cout<<endl;
		use++;
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
