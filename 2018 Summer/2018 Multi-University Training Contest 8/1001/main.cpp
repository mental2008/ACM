#include <bits/stdc++.h>
using namespace std;
#define mem(a, i) memset(a, i, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
typedef long long ll;
const ll mod = 998244353ll;
const int maxn = 2e5 + 5;
ll fact[maxn];
ll inv[maxn];
ll fiv[maxn];

ll quick_pow(ll a, ll n) {
    ll res = 1;
    ll p = a;
    while(n) {
        if(n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

void init() {
    fact[0] = fact[1] = 1;
    fiv[0] = fiv[1] = 1;
    inv[1] = 1;
    rep(i, 2, maxn - 1) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
        fiv[i] = 1ll * inv[i] * fiv[i - 1] % mod;
    }
}

ll C(ll m, ll k) {
    if(m < k || k < 0) return 0;
    return ((fact[m] * fiv[k]) % mod) * fiv[m - k] % mod;
}

int main()
{
    init();
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        ll ans = C(k + m - 1, m - 1);
        rep(i, 1, m) {
            if(i * n > k) break;
            ll temp = C(m, i) * C(k - i * n + m - 1, m - 1) % mod;
            if(i % 2) ans = ans - temp;
            else ans = ans + temp;
            ans = (ans % mod + mod) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
