#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using i64 = long long;
const int N = 1e6+10,INF=0x3f3f3f3f;
using namespace std;
string s1,s2;
int len;
int bfs(){
	queue<string>res;//bfs的任务队列；
	res.push(s1);//初始从初始态开始；
	unordered_map<string,int>sum;//存储每一个状态距离初始态的距离；
	sum[s1]=0;//初始距离为0；
	int dis[6]={1,-1,2,-2,3,-3};//定义偏移量；
	while(!res.empty()/*任务队列存在*/){
		string t=res.front();//提取任务；
		res.pop();//删除；
		int distence=sum[t];//该状态距离初始态的距离；
		if(t==s2){
			return distence;//已经成为末态，返回距离；
		}
		int p=t.find('*');//找到空杯子下标；
		for(int x=0;x<6;x++){
			int p2=p+dis[x];//空杯子在六种可能下的位置；
			if(p2>-1&&p2<len/*合法转移*/){
				swap(t[p],t[p2]);//交换位置，取得操作后的状态；
				if(sum.count(t)==0/*该状态未出现过，未存入距离map*//*!=0则相当于出现过，最先出现显然距离短，所有这个状态相同但距离长的不考虑，相当于复杂操作了*/){
					sum[t]=distence+1;
					res.push(t);//该新的合法状态放入任务队列方便下一次bfs；
				}
				swap(t[p],t[p2]);//还原状态；
			}
		}
	}
	return -1;
}
void solve() {
	cin>>s1>>s2;
	len=s1.size();
	cout<<bfs()<<endl;
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
