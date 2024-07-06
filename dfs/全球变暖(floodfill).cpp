#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
char a;
bool b[N][N];
int  c[N][N];
int n;
int xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
void flood_fill(int x,int y,int name){
	for(int z=0;z<4;z++){
		int mx=x+xx[z],my=y+yy[z];
		if(mx>=1&&mx<=n&&my>=1&&my<=n){
		if(!b[mx][my]&&c[mx][my]!=name/*很重要，记得判断是否为该次dfs走过的路，否则会回走，超时！！不要回走！！*/){
			c[mx][my]=name;	
			flood_fill(mx,my,name);				
			}
		}
	}	
}
void solve() {
	cin>>n;
	int ans=0;
	memset(b,false,sizeof b);
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			cin>>a;
			if(a=='.'){
				c[x][y]=-1,b[x][y]=true;
			}
			else c[x][y]=0;
		}
	}
	int f=1;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(c[x][y]==0){
				c[x][y]=f;
				flood_fill(x,y,f);
				f++;
			}
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(!b[x][y])for(int z=0;z<4;z++){
				int mx=x+xx[z],my=y+yy[z];
				if(mx>=1&&mx<=n&&my>=1&&my<=n){
					if(b[mx][my]){
						c[x][y]=-1;	
						break;				
					}
				}
			}	
		}
	}
	set<int>d;
	for(int x=1;x<=n;x++){
		for(int y=1;y<=n;y++){
			if(c[x][y]!=-1)d.insert(c[x][y]);
		}
	}
	cout<<f-1-d.size()<<endl;
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
