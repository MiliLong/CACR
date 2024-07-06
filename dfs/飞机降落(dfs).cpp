#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//dfs暴力所有情况，记得剪枝
int n;
bool flag,r[11];
struct stu{
	int t,d,l,e;
}a[11];
void dfs(int k,int last){
	k++;
	if(k>n){
		flag=true;//满足
		return;
	}
	if(flag)return;//剪枝
	for(int x=1;x<=n;x++){
		if(!r[x]){
			if(a[x].e<last)continue;//剪枝，最晚降落时，飞机还没下，不符合
			r[x]=true;//标记
			if(a[x].t>last){
				//最早降落大于last，那就最早起飞
				dfs(k,a[x].t+a[x].l);
			}
			else{
				//最早降落小于等于last，飞机降落完成就起飞
				dfs(k,last+a[x].l);
			}
			r[x]=false;//还原
		}
	}
}
void solve() {
	cin>>n;
	flag=false;
	memset(r,false,sizeof r);
	for(int x=1;x<=n;x++){
		cin>>a[x].t>>a[x].d>>a[x].l;
		a[x].e=a[x].t+a[x].d;//最晚降落时间
	}
	dfs(0,0);
	if(flag){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
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
