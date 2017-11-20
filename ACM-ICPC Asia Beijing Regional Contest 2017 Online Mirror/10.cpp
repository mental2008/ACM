#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
// int a[maxn];
// int f[maxn][maxn];
// int dp[maxn][maxn];
// int n, L, R;
// int sum[maxn][maxn];
// int main() {
//     while(~scanf("%d%d%d", &n, &L, &R)) {
//         for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
//         for(int i = 1; i <= n; ++i) {
//             sum[i][i] = a[i];
//             for(int j = i + 1; j <= n; ++j) {
//                 sum[i][j] = sum[i][j - 1] + a[j];
//             }
//         }
//         mem(dp, 0x3f);
//         for(int i = 1; i <= n; ++i) dp[i][i] = 0;
//         for(int i = n; i >= 1; --i) {
//             mem(f, 0x3f);
//             for(int j = i; j <= n; ++j) {
//                 f[j][j - i + 1] = 0;
//                 if(j - i + 1 <= R && j - i + 1 >= L) f[j][1] = sum[i][j];
//                 for(int k = j - i; k >= 1; --k) {
//                     f[j][k] = min(f[j][k], f[j - 1][k - 1]);
//                     for(int l = j - 1; l >= i; --l) {
//                         if(j - l < L || j - l > R) continue;
//                         f[j][k] = min(f[j][k], f[l][k - 1] + sum[l + 1][j]);
//                     }
//                 }
//                 for(int k = L - 1; k <= R - 1; ++k) {
//                     for(int l = i; l <= j - 1; ++l) {
//                         f[j][1] = min(f[j][1], f[l][k] + dp[l + 1][j] + sum[i][j]);
//                     }
//                 }
//             }
//             for(int j = i; j <= n; ++j) {
//                 for(int k = 1; k <= j - i + 1; ++k) {
//                     printf("%d %d %d %d\n", i, j, k, f[j][k]);
//                 }
//             }
//             for(int j = i; j <= n; ++j) {
//                 for(int k = L - 1; k <= R - 1; ++k) {
//                     for(int l = i; l <= j - 1; ++l) {
//                         dp[i][j] = min(dp[i][j], f[l][k] + dp[l + 1][j] + sum[i][j]);
//                     }
//                 }
//             }
//         }
//         printf("%d\n", (dp[1][n] >= INF ? 0 : dp[1][n]));
//     }
//     return 0;
// }cannot work

int a[maxn];
int dp[maxn][maxn][maxn];
int n, L, R;
int sum[maxn][maxn];
int main() {
    while(~scanf("%d%d%d", &n, &L, &R)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        mem(dp, 0x3f);
        for(int i = 1; i <= n; ++i) {
            sum[i][i - 1] = 0;
            for(int j = i; j <= n; ++j) {
                dp[i][j][j - i + 1] = 0;
                sum[i][j] = sum[i][j - 1] + a[j];
            }
        }
        for(int p = 1; p <= n - 1; ++p) {
            for(int i = 1; i + p <= n; ++i) {
                for(int l = i; l <= i + p - 1; ++l) {
                    for(int k = L - 1; k <= R - 1; ++k) {
                        dp[i][i + p][1] = min(dp[i][i + p][1], dp[i][l][k] + dp[l + 1][i + p][1] + sum[i][i + p]);
                    }
                }
                for(int k = 2; k <= p; ++k)
                    for(int l = i; l <= i + p - 1; ++l)
                        dp[i][i + p][k] = min(dp[i][i + p][k], dp[i][l][k - 1] + dp[l + 1][i + p][1]);
            }
        }
        printf("%d\n", (dp[1][n][1] >= INF ? 0 : dp[1][n][1]));
    }
    return 0;
}
