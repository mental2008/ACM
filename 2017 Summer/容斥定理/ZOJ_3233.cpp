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
int n, m;
LL a[20];
LL l, r;
LL BUN;

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

LL cal(LL border) {
    LL sum1 = 0;
    LL sum2 = 0;
    for(int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        LL temp = 1;
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1) {
                cnt++;
                temp = lcm(temp, a[j]);
            }
        }
        LL temp2 = lcm(BUN, temp);
        if(BUN < 0) {
            if(cnt % 2 == 1) sum1 += border / temp;
            else sum1 -= border / temp;
            continue;
        }
        if(cnt % 2 == 1) {
            sum1 += (border / temp);
            sum2 += (border / temp2);
        }
        else {
            sum1 -= (border / temp);
            sum2 -= (border / temp2);
        }
    }
    return sum1 - sum2;
}

int main() {
    while(~scanf("%d%d%lld%lld", &n, &m, &l, &r), n || m || l || r) {
        for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        BUN = 1;
        for(int i = 0; i < m; ++i) {
            LL val;
            scanf("%lld", &val);
            BUN = lcm(BUN, val);
        }
        LL ans = cal(r) - cal(l - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
