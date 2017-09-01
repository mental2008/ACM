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
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e5 + 5;
int n;
int fa[maxn];

struct Node {
    LL u, v, w;
    bool operator < (const Node& e) const {
        return w > e.w;
    }
} node[maxn];

int _find(int x) {
    return (fa[x] == x ? x : fa[x] = _find(fa[x]));
}

bool connect(int a, int b) {
    int x = _find(a);
    int y = _find(b);
    if(x == y) return false;
    else {
        fa[x] = y;
        return true;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) fa[i] = i;
        for(int i = 0; i < n - 1; ++i) {
            scanf("%lld%lld%lld", &node[i].u, &node[i].v, &node[i].w);
        }
        sort(node, node + n - 1);
        LL ans = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(connect(node[i].u, node[i].v)) {
                ans += node[i].w;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
