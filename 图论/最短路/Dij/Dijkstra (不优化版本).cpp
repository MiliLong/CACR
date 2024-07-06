#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N];  // 邻接矩阵
int dist[N];  // 存储 1 号点到该点的距离
bool vis[N];  // 最短路是否确定
int n, m;

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i ++) {  // 循环 n 次, 求出每个点的最短路径
        int t = -1;
        for (int j = 1; j <= n; j ++)        // 找到最短路未定的最小距离的那个点
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        vis[t] = true;

        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);  // 更新dist[0 ~ n]的最小值, 
        }
    }

    if (dist[n] == INF) return -1;  // 如果无法到达
    else return dist[n];
}


int main () {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);  // 多条边 取最权最小的那条边  (邻接矩阵两个点固定某个方向只能存一条边)
    }
    cout << dijkstra() << endl;
    return 0;
}
//www.acwing.com/activity/content/code/content/4948142/
