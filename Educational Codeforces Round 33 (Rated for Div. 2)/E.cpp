#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
LL fact[2 * maxn];
LL inv[2 * maxn];
LL fiv[2 * maxn];

void init() {
    fact[0] = fact[1] = 1;
    fiv[0] = fiv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < 2 * maxn; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
    }
}

LL C(LL m, LL k) {
    if(m < k || k < 0) return 0;
    LL sum =  (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
    return sum;
}

LL quick_pow(LL a, LL n) {
    LL p = (a % MOD);
    LL res = 1;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    init();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        LL x, y;
        scanf("%lld%lld", &x, &y);
        LL ans = quick_pow(2LL, y - 1);
        for(LL i = 2; i * i <= x; ++i) {
            if(x % i == 0) {
                LL num = 0;
                while(x % i == 0) {
                    x /= i;
                    num++;
                }
                ans = (ans * C(num + y - 1, y - 1)) % MOD;
            }
        }
        if(x > 1) ans = (ans * C(y, y - 1)) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
