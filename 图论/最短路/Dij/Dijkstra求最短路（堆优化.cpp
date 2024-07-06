#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;  // INF 表示无穷, 即到不了
bool vis[N];  // 是否是确定的最小路径
int h[N], w[N], e[N], ne[N], idx;  // 邻接表     w 是边权  
int dist[N];  //  1 节点到 该节点的距离
int n, m;

void add(int a, int b, int c) {
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++;  // 插入 + 赋值边权
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);  // 距离初始化
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;  // 小根堆
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;  // ver 是节点编号

        if (vis[ver]) continue;  // 过滤重边
        vis[ver] = 1;

        for (int i = h[ver]; i != -1; i = ne[i]) {  // 更新与该节点相连接的所有点的距离的最小值
            int j = e[i];  // 取出节点编号
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == INF) return -1;
    else return dist[n];
}


int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}
//www.acwing.com/activity/content/code/content/4948496/
