#include<bits/stdc++.h>
using namespace std;
//朴素的贪心思想
//按结束时间排序，一个一个往里放，不符合就跳过下一个；
bool cmp(pair<int ,int>a,pair<int ,int>b){
	return a.second<b.second;
}
void solve() {
int n;
while(scanf("%d",&n)){
	if(n==0)break;
	vector<pair<int ,int>>p;
	while(n--){
		int a,b;
		cin>>a>>b;
		pair<int,int>mid;
		mid.first=a,mid.second=b;
		p.push_back(mid);
	}
	sort(p.begin(),p.end(),cmp);
	auto f=p.begin();
	int as=0,e=(*f).second;
	for(auto &it:p){
	if(it.first>=e){
		as++;
		e=it.second;
	}	
		
	}
	cout<<as+1<<endl;
}
}
int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
