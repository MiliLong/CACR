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
//flyod也能过，两点间的距离是层数，对于任何一个输入遍历所有人找到存在距离并小于层数的ans++即可；
using namespace std;
int n,ll,k,M;
vector<set<int>>g(N);
int a[N],ma=0;
int bfs(int m,int s){
	int l=a[m];
	if(s>ll-1||l==0||(M==m&&s!=1)){
		return 0 ;
	}
	for(auto &it:g[m]){
		s++;
		ma++;
		bfs(it,s);
		s--;
	}
	return 0;
}
void solve() {
	cin>>n>>ll;
	for(int x=1;x<=n;x++){
		cin>>a[x];
		for(int y=1;y<=a[x];y++){
			int mid;
			cin>>mid;
			(g[x]).insert(mid);
		}
	}
	cin>>k;
	while(k--){
		ma=0;
		cin>>M;
		for(int x=1;x<=n;x++){
			if(x!=M)bfs(M,1);
		}
		cout<<ma<<endl;
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
