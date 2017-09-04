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
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
LL n;
int m;
LL a[12];

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

LL dfs(int depth, int last, LL LCM, int need) {
    if(depth < need && last == m - 1) return 0;
    if(depth == need) {
        return (LL)((n - 1.0) / LCM);
    }
    LL res = 0;
    for(int i = last + 1; i < m; ++i) {
        res += dfs(depth + 1, i, lcm(LCM, a[i]), need);
    }
    return res;
}

int main() {
    while(~scanf("%lld%d", &n, &m)) {
        for(int i = 0; i < m; ++i) {
            scanf("%lld", &a[i]);
        }
        LL ans = 0;
        for(int i = 1; i <= m; ++i) {
            if(i % 2 == 1) ans += dfs(0, -1, 1, i);
            else ans -= dfs(0, -1, 1, i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
