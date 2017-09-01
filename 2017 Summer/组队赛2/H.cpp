#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
int n, m;
LL H[50005];
bool vis[50005];
struct Node {
    LL val;
    LL addMark;
} node[3 * 50005];

void build(int root, int l, int r) {
    node[root].addMark = 0;
    if(l == r) {
        node[root].val = H[l];
        return;
    }
    node[root].val = 0;
    int mid = (l + r) / 2;
    build(root * 2, l, mid);
    build(root * 2 + 1, mid + 1, r);
}

void pushDown(int root) {
    if(node[root].addMark != 0) {
        LL temp = node[root].addMark;
        node[root * 2].addMark += temp;
        node[root * 2 + 1].addMark += temp;
        node[root * 2].val += temp;
        node[root * 2 + 1].val += temp;
        node[root].addMark = 0;
    }
}

void add(int root, int l, int r, int ql, int qr, LL p) {
    if(l > qr || r < ql) return;
    if(l >= ql && r <= qr) {
        node[root].addMark += p;
        node[root].val += p;
        return;
    }
    pushDown(root);
    int mid = (l + r) / 2;
    add(root * 2, l, mid, ql, qr, p);
    add(root * 2 + 1, mid + 1, r, ql, qr, p);
}

void update(int root, int l, int r, int index) {
    if(l > index || r < index) return;
    if(l == index && r == index) {
        H[index] = node[root].val;
        return;
    }
    pushDown(root);
    int mid = (l + r) / 2;
    update(root * 2, l, mid, index);
    update(root * 2 + 1, mid + 1, r, index);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &H[i]);
        }
        mem(vis, 0);
        int sum = 0;
        for(int i = 2; i < n; ++i) {
            if(H[i] > H[i - 1] && H[i] > H[i + 1]) {
                vis[i] = 1;
                sum++;
            }
        }
        build(1, 1, n);
        for(int i = 1; i <= m; ++i) {
            int lef, rig;
            LL p;
            scanf("%d%d%lld", &lef, &rig, &p);
            add(1, 1, n, lef, rig, p);
            for(int i = -2; i <= 1; ++i) {
                if(lef + i < 1 || lef + i > n) continue;
                update(1, 1, n, lef + i);
            }
            if(lef - 2 >= 1 && lef <= n) {
                if(!vis[lef - 1] && H[lef - 1] > H[lef - 2] && H[lef - 1] > H[lef]) {
                    vis[lef - 1] = 1;
                    sum++;
                }
                else if(vis[lef - 1] && (H[lef - 1] <= H[lef - 2] || H[lef - 1] <= H[lef])) {
                    vis[lef - 1] = 0;
                    sum--;
                }
            }
            if(lef - 1 >= 1 && lef + 1 <= n) {
                if(!vis[lef] && H[lef] > H[lef - 1] && H[lef] > H[lef + 1]) {
                    vis[lef] = 1;
                    sum++;
                }
                else if(vis[lef] && (H[lef] <= H[lef - 1] || H[lef] <= H[lef + 1])) {
                    vis[lef] = 0;
                    sum--;
                }
            }
            for(int i = -1; i <= 2; ++i) {
                if(rig + i < 1 || rig + i > n) continue;
                update(1, 1, n, rig + i);
            }
            if(rig + 2 <= n && rig >= 1) {
                if(!vis[rig + 1] && H[rig + 1] > H[rig + 2] && H[rig + 1] > H[rig]) {
                    vis[rig + 1] = 1;
                    sum++;
                }
                else if(vis[rig + 1] && (H[rig + 1] <= H[rig + 2] || H[rig + 1] <= H[rig])) {
                    vis[rig + 1] = 0;
                    sum--;
                }
            }
            if(rig - 1 >= 1 && rig + 1 <= n) {
                if(!vis[rig] && H[rig] > H[rig + 1] && H[rig] > H[rig - 1]) {
                    vis[rig] = 1;
                    sum++;
                }
                else if(vis[rig] && (H[rig] <= H[rig + 1] || H[rig] <= H[rig - 1])) {
                    vis[rig] = 0;
                    sum--;
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
