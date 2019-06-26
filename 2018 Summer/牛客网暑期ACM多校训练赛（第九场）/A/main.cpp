#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv2 = (mod + 1) >> 1;
const int maxn = 262144 * 2 + 5;
ll a[maxn];
ll b[maxn];

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

struct FWT {
    int N;
    void init(int n) {
        N = 1;
        while(N < n) N <<= 1;
    }
    void FWT_xor(ll *a, int opt) {
        for(int i = 1; i < N; i <<= 1)
            for(int p = i << 1, j = 0; j < N; j += p)
                for(int k = 0; k < i; ++k) {
                    ll x = a[j + k], y = a[i + j + k];
                    a[j + k] = (x + y) % mod;
                    a[i + j + k] = (x + mod - y) % mod;
                    if(opt == -1) {
                        a[j + k] = 1ll * a[j + k] * inv2 % mod;
                        a[i + j + k] = 1ll * a[i + j + k] * inv2 % mod;
                    }
                }
    }
} fwt;

int main()
{
    int n;
    scanf("%d", &n);
    fwt.init(n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
    fwt.FWT_xor(a, 1);
    fwt.FWT_xor(b, 1);
    for(int i = 0; i < fwt.N; ++i) a[i] = b[i] * quick_pow(a[i], mod - 2) % mod;
    fwt.FWT_xor(a, -1);
    for(int i = 0; i < n; ++i) {
        printf("%lld\n", a[i]);
    }
    return 0;
}
