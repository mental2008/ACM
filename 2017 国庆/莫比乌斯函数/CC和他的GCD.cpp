#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
typedef long long LL;
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 100005;
int val[maxn];
LL fact[maxn], fiv[maxn], inv[maxn];
int mu[maxn];
int prime[maxn];
bool vis[maxn];
int cnt;

void init() {
    fact[0] = fact[1] = 1;
    fiv[0] = fiv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
    }
}

void Mobius() {
    int n = maxn;
    mem(prime, 0);
    mem(vis, 0);
    mem(mu, 0);
    mu[1] = 1;
    cnt = 0;
    for(int i = 2; i < n; ++i) {
        if(!vis[i]) {
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < cnt && i * prime[j] < n; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}

LL C(LL m, LL k) {
    if(m < k || k < 0) return 0;
    LL sum = (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
    return sum;
}

int main() {
    init();
    Mobius();
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        mem(val, 0);
        for(int i = 0; i < n; ++i) {
            int u;
            scanf("%d", &u);
            val[u]++;
        }
        LL ans = 0;
        for(int i = 2; i <= 100000; ++i) {
            int num = 0;
            for(int j = i; j <= 100000; j += i) {
                num += val[j];
            }
            ans = (ans + MOD - C(num, m) * mu[i]) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
