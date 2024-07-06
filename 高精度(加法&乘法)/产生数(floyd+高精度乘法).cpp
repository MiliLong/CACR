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
const int N = 1e3+10,INF=0x3f3f3f3f;
using namespace std;
string n;
int m;
int g[N][N];
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (t) C.push_back(t % 10), t /= 10;

    return C;
}
void floyd(){
	for(int z=0;z<10;z++){
		for(int x=0;x<10;x++){
			for(int y=0;y<10;y++){
				g[x][y]=min(g[x][y],g[x][z]+g[z][y]);
			}
		}
	}
}
void solve() {
	for(int x=0;x<=10;x++){
		for(int y=0;y<=10;y++){
			if(x==y)g[x][y]=0;
			else g[x][y]=INF;
		}
	}
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		g[a][b]=1;
	}
	floyd();
	vector<int>ans;
	ans.push_back(1);
	for(int x=0;x<n.size();x++){
		int q=n[x]-'0';
		int res=1;
		for(int i=0;i<10;i++){
			if(g[q][i]&&g[q][i]!=INF&&i!=0)res++;
		}
		ans=mul(ans,res);
	}
	 for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
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
