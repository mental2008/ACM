#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv2 = (mod + 1) >> 1;
const int maxn = 5e5 + 5;
ll a[maxn * 2];
ll b[maxn * 2];

struct FWT {
    int N;
    void init(int n) {
        N = 1;
        while (N < n)
            N <<= 1;
    }
    void FWT_or(ll *a, int opt) {
        for (int i = 1; i < N; i <<= 1)
            for (int p = i << 1, j = 0; j < N; j += p)
                for (int k = 0; k < i; ++k)
                    if (opt == 1)
                        a[i + j + k] = (a[j + k] + a[i + j + k]) % mod;
                    else
                        a[i + j + k] = (a[i + j + k] + mod - a[j + k]) % mod;
    }
    void FWT_and(ll *a, int opt) {
        for (int i = 1; i < N; i <<= 1)
            for (int p = i << 1, j = 0; j < N; j += p)
                for (int k = 0; k < i; ++k)
                    if (opt == 1)
                        a[j + k] = (a[j + k] + a[i + j + k]) % mod;
                    else
                        a[j + k] = (a[j + k] + mod - a[i + j + k]) % mod;
    }
    void FWT_xor(ll *a, int op) {
        for (int i = 1; i < N; i <<= 1)
            for (int p = i << 1, j = 0; j < N; j += p)
                for (int k = 0; k < i; ++k)
                {
                    ll x = a[j + k], y = a[i + j + k];
                    a[j + k] = (x + y) % mod;
                    a[i + j + k] = (x + mod - y) % mod;
                    if (op == -1)
                    {
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
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int MAX = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        a[val] = b[val] = 1;
        MAX = max(MAX, val);
        sum ^= val;
    }
    if(sum == 0) return printf("%d\n", n), 0;
    n--;
    fwt.init(MAX + 1);
    a[0] = b[0] = 1;
    fwt.FWT_xor(b, 1);
    while(a[sum] == 0) {
        n--;
        fwt.FWT_xor(a, 1);
        for(int i = 0; i < fwt.N; ++i) a[i] *= b[i];
        fwt.FWT_xor(a, -1);
        for(int i = 0; i < fwt.N; ++i) a[i] = (a[i] != 0);
    }
    printf("%d\n", n);
    return 0;
}
