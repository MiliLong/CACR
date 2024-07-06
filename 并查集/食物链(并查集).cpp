#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
using ll = long long;
const int N = 5e5 + 10, INF = 0x3f3f3f3f;
int f[3 * N + 10];
int n, k, ans = 0;
using namespace std;
//食物链扩展域写法
//动物直接关系为捕食，同类，天敌，所以我们开三倍的数组分别存三种关系
//0->N存储同类关系，N+1->2*N存储捕食关系（即吃谁），2*N+1->3*N存储天敌关系（即被谁吃）
//find，Union都不变，特判条件记得先判，具体细节见下处注释
void init() {
	for (int x = 1; x <= 3 * N - 1; x++) {
		f[x] = x;
		//初始化记得初始完全3n
	}
}
int find(int a) {
	if (f[a] == a)return a;
	int as = find(f[a]);
	return f[a] = as;
}
void Union(int a, int b) {
	int fa = find(a), fb = find(b);
	f[fb] = fa;
	//这里不必考虑正反，fb，fa位置可互换
	//只是选个族长而已，谁都一样
}
void solve() {
	cin >> n >> k;
	init();
	while (k--) {
		int c, a, b;
		cin >> c >> a >> b;
		if (a > n || b > n)ans++;
		else if (c == 2 && a == b)ans++;
		else {
			if (c == 1) {
				//若不满足同类关系则肯定是捕食关系，接下来判断两种情况，捕食关系互换
				if (find(a) == find(b + N) || find(b) == find(a + N)) {
					ans++;
					continue;
				}
				//同理则Union，继承所有关系，同族，捕食族，天敌族
				Union(a, b);
				Union(a + N, b + N);
				Union(a + 2 * N, b + 2 * N);
			}
			else if (c == 2) {
				//若为a吃b，首先不是同类，其次b不吃a，判断一下
				if (find(a) == find(b) || find(a) == find(b + N)) {
					ans++;
					continue;
				}
				//a吃b，联合a的同族和b的天敌族（其实表示一个族），同理，联合a的捕食族和b的同族，联合a的天敌族和b的捕食族
				Union(a, b + 2 * N);
				Union(a + N, b);
				Union(a + 2 * N, b + N);
			}
		}
	}
	cout << ans << endl;
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
