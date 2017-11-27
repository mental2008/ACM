#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
LL dp[2700];
LL a[75];

LL quick_pow(LL a, LL n) {
    LL p = a;
    LL res = 1;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i) {
        int val;
        scanf("%d", &val);
        a[val]++;
    }
    for(int i = 2; i <= 2650; ++i) {
        if(i <= 70) dp[i] = a[i] * a[i] % MOD;
        else dp[i] = 0;
        for(int j = 2; j * j <= i; ++j) {
            if(i % j == 0) {
                dp[i] = (dp[i] % MOD + dp[j] * dp[i / j] % MOD) % MOD;
            }
        }
        if(i <= 10) printf("i = %d dp[i] = %lld\n", i, dp[i]);
    }
    LL sum = 0;
    for(int i = 2; i <= 2650; ++i) sum = (sum + dp[i]) % MOD;
    sum = (sum * quick_pow(2, a[1])) % MOD;
    sum = (sum + (quick_pow(2, a[1]) - 1) % MOD) % MOD;
    sum = (sum % MOD + MOD) % MOD;
    printf("%lld\n", sum);
    return 0;
}
