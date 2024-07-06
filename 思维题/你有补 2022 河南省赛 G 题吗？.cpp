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
//操作是假的，无论怎么操作，这一列与后是1还是0是确定的，把其中j一个列上的位置改为1
//的前提是两者都为1，一旦这一列不全为1怎么操作与后都为0
void solve() {
	int n,m;
	cin>>n>>m;
	vector<string>u(n+1);
	int cnt[m+1];
	memset(cnt,0,sizeof cnt);
	for(int x=1;x<=n;x++){
		cin>>u[x];
		for(int y=1;y<=m;y++){
			if(u[x][y-1]=='1')cnt[y]++;
		}
	}
	int q;cin>>q;
	int i,j,l,r,p;
	for(int x=1;x<=q;x++){
		cin>>i>>j>>l>>r>>p;
	}
	int ans=0;
	for(int x=1;x<=m;x++){
		if(cnt[x]==n)ans++;
	}
	cout<<ans<<endl;
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
