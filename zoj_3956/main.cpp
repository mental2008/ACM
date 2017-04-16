#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500
#define LL long long
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        LL H[maxn + 10], C[maxn + 10];
        LL dp[maxn * 100 + 10];
        memset(dp, 0, sizeof(dp));
        int maxc = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lld%lld", &H[i], &C[i]);
            maxc += C[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = maxc; j >= C[i]; j--) {
                dp[j] = max(dp[j], dp[j - C[i]] + H[i]);
            }
        }
        LL ans = 0;
        for(int i = 0; i <= maxc; i++) {
            ans = max(ans, dp[i] * dp[i] - dp[i] * i - i * i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}