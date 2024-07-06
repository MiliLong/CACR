#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
struct Node {
    int l, r;
    LL sum, add;  // sum 是区间属性   add是懒标记
}tr[N * 4];
int n, m;
int w[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum += root.add * (left.r - left.l + 1); 
        right.add += root.add, right.sum += root.add * (right.r - right.l + 1); 
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, w[r], 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, LL d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += d * (tr[u].r - tr[u].l + 1);
        tr[u].add += d;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else {
        pushdown(u);

        LL sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) sum += query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        
        return sum;
    }
}


int main() {
    IOS;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> w[i];
    
    build(1, 1, n);
    
    int op;
    while (m --) {
        cin >> op;
        if (op == 2) {
            int l, r; cin >> l >> r;
            cout << query(1, l, r) << "\n";
        } else {
            int l, r, d; cin >> l >> r >> d;
            modify(1, l, r, d);
        }
    }
    
    return 0;
}