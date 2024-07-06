#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e1+10,INF=0x3f3f3f3f;
using namespace std;
ll n,w,a[N],ans,bus[N];
void dfs(ll m,ll cnt){
	if(cnt>=ans)return;//剪枝
	if(m==n+1){
		ans=min(cnt,ans);//n只猫猫放完了捏
		return;
	}
	for(int x=1;x<=cnt;x++){
		if(bus[x]+a[m]<=w){
			bus[x]+=a[m];
			dfs(m+1,cnt);
			bus[x]-=a[m];//还原很重要
		}
	}
	bus[cnt+1]=a[m];//除了现有的车还可以开新车
	dfs(m+1,cnt+1);
	bus[cnt+1]=0;//新车也要还原
}
void solve() {
	memset(bus,0,sizeof bus);
	cin>>n>>w;
	ans=n;
	for(int x=1;x<=n;x++){
		cin>>a[x];
	}
	sort(a+1,a+1+n,greater<ll>());//排序可以有效的加快速度
	//先放大的剩余的空间就变小了，小猫就可以放的方案就少了，自然效率高了，由于大猫早晚要放，所以先放更好
	dfs(1,0);
	cout<<ans<<endl;
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
