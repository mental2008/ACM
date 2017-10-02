#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n, k, r;
int a[maxn];
struct Node {
    int val;
} node[3 * maxn];

void build(int root, int l, int r) {
    if(l == r) {
        node[root].val = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    node[root].val = node[root * 2].val + node[root * 2 + 1].val;
}

int query(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) {
        return node[root].val;
    }
    int mid = (l + r) / 2;
    return query(root * 2, l, mid, ql, qr) + query(root * 2 + 1, mid + 1, r, ql, qr);
}

void update(int root, int l, int r, int index) {
    if(l > index || r < index) return;
    if(l == r) {
        a[l] = 1;
        node[root].val = 1;
        return;
    }
    int mid = (l + r) / 2;
    update(root * 2, l, mid, index);
    update(root * 2 + 1, mid + 1, r, index);
    node[root].val = node[root * 2].val + node[root * 2 + 1].val;
}

int main() {
    while(~scanf("%d%d%d", &n, &k, &r)) {
        mem(a, 0);
        for(int i = 1; i <= k; ++i) {
            int w;
            scanf("%d", &w);
            a[w] = 1;
        }
        build(1, 1, n);
        int ans = 0;
        for(int i = 1; i <= n + 1 - r; ++i) {
            int res = query(1, 1, n, i, i + r - 1);
            if(res >= 2) continue;
            int num = 2 - res;
            for(int j = i + r - 1; j >= i; --j) {
                if(num == 0) break;
                if(!a[j]) {
                    update(1, 1, n, j);
                    ans++;
                    num--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
