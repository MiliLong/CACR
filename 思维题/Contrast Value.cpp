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
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
//连续相等的只留1个，递增或递减的只留两端，注意1 2 3 4 3 2 1，delete 2 3 3 2，answer=3
int n,a[N],c[N];
void solve() {
	cin>>n;
	int s=0;
	for(int x=1;x<=n;x++)cin>>a[x],c[x]=a[x]-a[x-1],s+=abs(c[x]);
	if(n==1||s==0){
		cout<<1<<endl;
		return;
	}
	vector<int>ans;
	int sum=n;
	for(int x=1;x<=n;x++){
		if(ans.size()==0)ans.emplace_back(a[x]);
		else if(ans.size()==1){
			if(ans.back()==a[x])sum--;
			else ans.emplace_back(a[x]);
		}
		else {
			int e=ans.back(),f=*ans.begin();
			if(a[x]==e)sum--;
			else if(a[x]<e&&e<f){
				ans.emplace_back(a[x]);
				sum--;
			}
			else if(a[x]>e&&e>f){
				sum--;
				ans.emplace_back(a[x]);
			}
			else {
				ans.clear();
				ans.emplace_back(e);
				ans.emplace_back(a[x]);
			}
		}
	}
	cout<<sum<<endl;
}
signed main () {
	ios::sync_with_stdio(0), cin.tie(0);
	int T = 1;
	cin >> T,cin.get();
	while (T--) {
		solve();
	}
	return 0;
}
