#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int maxn = 100005;
LL q, k;
LL dp[maxn][2];
LL sum[maxn];

int main()
{
    scanf("%lld%lld", &q, &k);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i < maxn; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        if(i >= k) {
            dp[i][1] = dp[i - k][0] % MOD;
        }
    }
    memset(sum, 0, sizeof(sum));
    sum[0] = (dp[0][0] + dp[0][1]) % MOD;
    for(int i = 1; i < maxn; ++i) {
        sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % MOD;
    }
    while(q--) {
        LL l, r;
        scanf("%lld%lld", &l, &r);
        LL ans = sum[r] - sum[l - 1];
        ans = (ans % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
