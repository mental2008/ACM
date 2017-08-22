#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;
int a[maxn];
LL dp[maxn][2];

int main() {
    freopen("azerah.in", "r", stdin);
    freopen("azerah.out", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0) {
                dp[i][0] = 2 * dp[i - 1][0] % MOD;
                dp[i][1] = 2 * dp[i - 1][1] % MOD;
            }
            else {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            }
        }
        printf("%lld\n", dp[n][0] - 1);//减去都不选的情况
    }
    return 0;
}
