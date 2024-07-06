#include<bits/stdc++.h>
#define endl '\n'
#define deg(a) cout<<#a<<'='<<a<<"\n"
#define de(a) cout<<#a<<'='<<a<<' '
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define PII pair<int ,int>
#define int long long
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
using namespace std;
int n, a[N], tree[N], M = 0, f;
vector<int>r;
int lowbit(int x) {
    return x & (-x);
}
void add(int a, int b) {
    //收到告诉后add自动比较多次告诉的大小，维护max，不过是往a后维护哦
    for (int x = a; x <= n; x += lowbit(x)) {
        tree[x] = max(tree[x], b); //更新往后所有，替换为以该位置为结尾的最大上升序列的和
    }
}
int sum(int a) {
    //此时sum找的就是离散化后最大值小于a的各个每个x位置为结尾的最大上升子序列的值
    int res = 0;
    for (int x = a; x > 0; x -= lowbit(x)) {
        //收到询问那么就遍历之前所有告诉，尽管告诉已经维护max，但维护行为是往后维护前面不会维护，所有还要遍历所有告诉维护max
        res = max(tree[x], res); //找最大的就行，所有情况的最大值必定小于a的，若无就初始的res=0
    }
    return res;
}
//既然引入告诉和收到消息的类比，那么在引入一个概念方便理解，add中持续变化的x就是把告诉信息投到的位置，sum中变化的x就是收消息是去翻找的信箱
//在这个过程中一个告诉相当于投了很多信箱，信箱会对投入的信件处理，只会留最大数字的信件，收消息找信箱的过程也是翻找很多信箱，但只会留最大数字的信件
//抛开设定的概念更深度理解一下：：类比原来的树状数组，add函数在不同坐标tree加值的过程肯定能影响到后面所有坐标的前缀和，毕竟都加这个数了
//，而sum函数res一直跳着加tree的值，无论怎么跳叠加起来的值一定是前面所有数所造成影响的叠加，那么可知sum过程能获得前面所有的影响，获得同一位置影响只会发一次哦
//在这一题中我们把影响的方式改为更新max，毕竟我们不需要加值（相当于叠加影响），我们只需要维护max（即对各个影响取最大）
//这里的影响就是更新离散化后最大值小于a的各个每个x位置为结尾的最大上升子序列的值
////tree[x]维护的是数组中的某几个特定位置的属性
//在这里sum函数的名字就不是很合适了，其实应该改为max，其名字应和我们要遍历某几个特定位置的属性，对这些属性具体操作的方式相吻合
//可以是sum，可以是max,min等等
/*
最值：：最大上升子序列的值
便于理解，这里手动模拟一下：：
4
1 9 7 10
20
离散化后：：1 3 2 4
1->1::f=sum(0)::{res=0}+1=1,add(1,1)此时相当于告诉1后面所有的tree，此时在你前面比你小的数的最值为1
9->3::f=sum(2)::{res=0，收到之前的消息1>0,取1了}+9=10，add(3,10)此时相当于告诉3后面所有的tree，此时在你前面比你小的数的最值为10
7->2::f=sum(1)::{res=0,收到之前的消息1>0/为什么没收到10呢?因为10的消息发送到3位置后的所有tree了，2位置没收到/,取1了}+2=3,此时相当于告诉2后面所有的tree，此时在你前面比你小的数的最值为3
10->4::f=sum(3)::{res=0,收到之前的消息10>0,3>0,1>0(其实应该不会收完这三个消息，有之前树状数组可知它并不会遍历完，但由于过程中维护max，所以肯定在查询后收到10>0的消息),取10了}+10=20，略
由于一直在维护max，此时求出最大值为20
*/
int find(int x) {
    return lower_bound(all(r), x) - r.begin() + 1; //lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素
    //减去初始迭代器就是等效数组下标，这里加1因为从1开始
}
void solve() {
    cin >> n;
    for (int x = 1; x <= n; x++) {
        cin >> a[x];
        r.push_back(a[x]);
    }
    sort(all(r));
    r.erase(unique(all(r)), r.end()); //unique(all(r))返回去重序列的后一个迭代器
    //离散化标准过程，r复制a，r去重，r排序，定义find函数
    for (int x = 1; x <= n; x++) {
        int p = find(a[x]); //找到该数排第几
        f = sum(p - 1) + a[x]; //sum(p-1),相当于找最大值比它小的最大上升子序列
        add(p, f); //更新一下p位置的最大上升子序列
        M = max(f, M); //相当于每个位置为结尾的最大上升子序列维护max
    }
    cout << M << endl;
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
