#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100000
#define LL long long
using namespace std;
int n;
LL a[maxn << 1];

struct SegTree {
    LL val;
    LL addMark;
} node[maxn * 3];

void build(int root, int l, int r) {
    node[root].addMark = 0;
    node[root].val = 0;
    if(l == r) return;
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
}

void pushDown(int root) {
    if(node[root].addMark != 0) {
        LL tmp = node[root].addMark;
        node[root * 2].val += tmp;
        node[root * 2 + 1].val += tmp;
        node[root * 2].addMark += tmp;
        node[root * 2 + 1].addMark += tmp;
        node[root].addMark = 0;
        return;
    }
}

void update(int root, int l, int r, int ql, int qr) {
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        node[root].addMark += 1;
        node[root].val += 1;
        return;
    }
    pushDown(root);
    int mid = (l + r) / 2;
    update(root * 2, l, mid, ql, qr);
    update(root * 2 + 1, mid + 1, r, ql, qr);
}

void cal(int root, int l, int r) {
    if(l == r) {
        a[l] = node[root].val;
        return;
    }
    pushDown(root);
    int mid = (l + r) / 2;
    cal(root * 2, l, mid);
    cal(root * 2 + 1, mid + 1, r);
}

int main() {
    while(scanf("%d", &n) && n) {
        memset(a, 0, sizeof(a));
        build(1, 1, n);
        for(int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            update(1, 1, n, a, b);
        }
        cal(1, 1, n);
        for(int i = 1; i <= n; i++) {
            if(i != 1) printf(" ");
            printf("%lld", a[i]);
        }
        printf("\n");
    }
    return 0;
}