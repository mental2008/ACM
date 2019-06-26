#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int maxn = 505;
int dp[maxn][maxn];
int fact[maxn];
int inv[maxn];
int fiv[maxn];

int C(int n, int m) {
    if(n < m || m < 0) return 0;
    int sum = (1LL * fact[n] * fiv[m] % MOD) * fiv[n - m] % MOD;
    return sum;
}

int quick_pow(int a, int n) {
    int res = 1;
    int p = a;
    while(n) {
        if(n & 1) res = (1LL * res * p) % MOD;
        p = (1LL * p * p) % MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    fact[0] = fact[1] = 1;
    fiv[0] = fiv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
    }
    mem(dp, 0);
    dp[1][1] = 1;
    for(int i = 2; i <= 500; ++i) {
        dp[i][i] = 1;
        for(int j = 2; j < i; ++j) {
            for(int k = 1; k <= i - j + 1; ++k) {
                dp[i][j] = (dp[i][j] + (1LL * dp[i - k][j - 1] * C(i - 1, k - 1) % MOD) * dp[k][1] % MOD) % MOD;
            }
        }
        dp[i][1] = quick_pow(2, i * (i - 1) / 2) % MOD;
        for(int j = 2; j <= i; ++j) {
            dp[i][1] = (dp[i][1] - dp[i][j]) % MOD;
            dp[i][1] = (dp[i][1] % MOD + MOD) % MOD;
        }
    }
}

int main() {
    solve();
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(m == 1) {
            int ans = dp[n][m] - 1;
            ans = (ans % MOD + MOD) % MOD;
            printf("%d\n", ans);
        }
        else printf("%d\n", dp[n][m]);
    }
    return 0;
}
