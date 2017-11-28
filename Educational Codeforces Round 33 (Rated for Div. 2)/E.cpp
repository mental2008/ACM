#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
LL prime[maxn];
bool isprime[maxn];
LL fact[maxn];
LL inv[maxn];
LL fiv[maxn];
int cnt;

void init() {
    mem(isprime, 0);
    cnt = 0;
    for(int i = 2; i < maxn; ++i) {
        if(!isprime[i]) {
            prime[cnt] = 1LL * i;
            cnt++;
        }
        for(int j = 0; j < cnt && i * prime[j] < maxn; ++j) {
            isprime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    fact[0] = fact[1] = 1LL;
    fiv[0] = fiv[1] = 1LL;
    inv[1] = 1LL;
    for(int i = 2; i < maxn; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
    }
}

LL C(LL m, LL k) {
    if(m < k || k < 0) return 0;
    return (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
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
        LL ans = 1LL;
        for(int i = 0; i < cnt; ++i) {
            if(prime[i] > x) break;
            if(x % prime[i] == 0) {
                LL num = 0;
                while(x % prime[i] == 0) {
                    x /= prime[i];
                    num++;
                }
                ans = (ans * C(num + y - 1, y - 1)) % MOD;
            }
        }
        if(x != 1) ans = (ans * C(y, y - 1)) % MOD;
        ans = (ans * quick_pow(2LL, y - 1)) % MOD;
        ans = (ans % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
