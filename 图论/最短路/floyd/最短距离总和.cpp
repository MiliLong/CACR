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
const int N = 5e2+10,INF=0x3f3f3f3f;
using namespace std;
void solve() {
	int n;
	cin>>n;
	int g[N][N];
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			cin>>g[x][y];
		}
	}
	function<int()>floyd=[&](){
		int ans=0;
		for(int z=n;z>=2;z--){
			for(int x=1;x<=n-1;x++){
				for(int y=x+1;y<=n;y++){
					g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
					g[y][x]=g[x][y];
				}
			}
			for(int x=z;x<=n-1;x++){
				for(int y=x;y<=n;y++){
					ans+=g[x][y];	
				}
			}
		}
		return ans*2;
	};
	cout<<floyd()<<endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
