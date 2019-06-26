#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int b[maxn];
int n, q;
int seg[maxn * 4];
int addMark[maxn * 4];
int tree[maxn];

void build(int root, int l, int r) {
    addMark[root] = 0;
    if(l == r) {
        seg[root] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
    seg[root] = min(seg[root * 2], seg[root * 2 + 1]);
}

void pushDown(int root) {
    if(addMark[root] != 0) {
        addMark[root * 2] += addMark[root];
        addMark[root * 2 + 1] += addMark[root];
        seg[root * 2] -= addMark[root];
        seg[root * 2 + 1] -= addMark[root];
        addMark[root] = 0;
        return;
    }
}

inline int lowbit(int x) {
    return (x & -x);
}

void add(int x) {
    for(int i = x; i <= n; i += lowbit(i)) {
        tree[i]++;
    }
}

int get(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

void upload(int root, int l, int r) {
    if(l == r) {
        seg[root] = b[l];
        add(l);
        return;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    if(seg[root * 2] == 0) upload(root * 2, l, mid);
    if(seg[root * 2 + 1] == 0) upload(root * 2 + 1, mid + 1, r);
    seg[root] = min(seg[root * 2], seg[root * 2 + 1]);
}

void update(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        seg[root]--;
        addMark[root]++;
        if(seg[root] == 0) {
            upload(root, l, r);
        }
        return;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    update(root * 2, l, mid, ql, qr);
    update(root * 2 + 1, mid + 1, r, ql, qr);
    seg[root] = min(seg[root * 2], seg[root * 2 + 1]);
}

int main()
{
    while(~scanf("%d%d", &n, &q)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        build(1, 1, n);
        memset(tree, 0, sizeof(tree));
        while(q--) {
            char s[10];
            int l, r;
            scanf("%s", s);
            scanf("%d%d", &l, &r);
            if(s[0] == 'a') {
                update(1, 1, n, l, r);
            }
            else {
                int ans = get(r) - get(l - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
