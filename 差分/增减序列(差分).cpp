#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long 
const int N = 1e5+10,INF=0x3f3f3f3f;
using namespace std;
int n,a[N],c[N];
void solve() {
	cin>>n;
	for(int x=1;x<=n;x++)cin>>a[x],c[x]=a[x]-a[x-1];
	int p=0,q=0;
	//我们的目的是让2往后的c[]为0，那么显然其前缀和获得的数组所有值相同
	for(int x=2;x<=n;x++){
		if(c[x]>0)p+=c[x];
		else q-=c[x];
	}
	/*
	举个例子：：
	假设一个c[]为：：？ 5 -4 3 6 1
	由于我们每一次操作都可以让一个区间的头尾分别+,-或-,+,为了最高效利用操作
	让所有值最接近0，我们每次挑选一对+，-的值，让其相互抵消
	把-4消去的手法就是+4，那么后面有一个位置需要-4，如？ 5 0 3 2 1
	此时，我们进行了4次操作。这里p代表+的叠加，q为-的叠加，接下来找+-对
	先正负抵消，即当你对一个+位置-时就可以对一个-位置+，差分的常规操作
	最后剩的全为+/-，此时我们再进行剩下的操作即可，此时由于c[1]我们是
	可以随便操作的可以和剩下的进行抵消，总共abs(p-q)+min(p,q)次
	在我们将+-抵消后还剩余abs(p-q)个需要处理，对于每个1，假设其所属位置为
	x,其存在会使x->n加1，我们有两种操作可选，1是x前所有数加1，2是x即x后所有数减1
	我们有abs(p-q)个选择，后果是，我们对c[1]的加1操作可为0->abs(p-q)次，不论c[1]
	的初始值，我们获得了abs(p-q)+1个c[1]的类别，所以最终能得到abs(p-q)+1种结果
	*/
	cout<<abs(p-q)+min(p,q)<<endl;
	cout<<abs(p-q)+1<<endl;
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
