#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 1e6 + 10;

constexpr int M = N << 1;
constexpr int lg2 = __lg(N);
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][lg2 + 1];
int q[N];

void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs(int root) {
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;

    q[0] = root;
    int hh = 0, tt = 0;
    while (hh <= tt) {
        int t = q[hh ++];
        for (int i = h[t]; i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                q[++tt] = j;

                depth[j] = depth[t] + 1;
                fa[j][0] = t;
                for (int k = 1; k <= lg2; k ++)
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = lg2; k >= 0; k --)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = lg2; k >= 0; k --)
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}
