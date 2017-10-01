#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
int n;
LL a[65];
LL pre[65];
LL dp[65][65][65][65];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        int num = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == a[1]) num++;
        }
        pre[0] = 1;
        for(int i = 1; i <= num; ++i) {
            pre[i] = (pre[i - 1] * i) % MOD;
        }
        for(int i = 2; i + num - 1 <= n; ++i) {
            a[i] = a[i + num - 1];
        }
        n = n - num + 1;
        mem(dp, 0);
        dp[1][0][0][1] = 1;
        LL ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    for(int l = 1; l <= n; ++l) {
                        int temp = max(i, l) + 1;
                        if(temp == n + 1) {
                            ans = (ans + dp[i][j][k][l]) % MOD;
                            continue;
                        }
                        if(j == 0 || a[j] - a[i] >= a[i] - a[temp]) {
                            dp[temp][i][k][l] = (dp[temp][i][k][l] + dp[i][j][k][l]) % MOD;
                        }
                        if(k == 0 || a[temp] - a[l] >= a[l] - a[k]) {
                            dp[i][j][l][temp] = (dp[i][j][l][temp] + dp[i][j][k][l]) % MOD;
                        }
                    }
                }
            }
        }
        ans = (ans * pre[num]) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
