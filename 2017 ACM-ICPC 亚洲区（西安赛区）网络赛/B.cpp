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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);

LL quick_pow(LL x, LL n) {
    LL res = 1;
    LL p = x % MOD;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return res % MOD;
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        LL p, q, k;
        scanf("%lld%lld%lld", &p, &q, &k);
        if(k % 2 == 0) {
            LL x = (quick_pow(p, k) + quick_pow(2 * q - p, k)) % MOD;
            LL y = 2 * quick_pow(p, k) % MOD;
            LL temp = quick_pow(y, MOD - 2);
            LL ans = x * temp % MOD;
            printf("%lld\n", (ans % MOD + MOD) % MOD);
        }
        else {
            LL x = (quick_pow(p, k) - quick_pow(2 * q - p, k)) % MOD;
            LL y = 2 * quick_pow(p, k) % MOD;
            LL temp = quick_pow(y, MOD - 2);
            LL ans = x * temp % MOD;
            printf("%lld\n", (ans + MOD % MOD) % MOD);
        }
    }
    return 0;
}
