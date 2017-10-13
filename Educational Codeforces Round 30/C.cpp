#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 105;
int n, m, k;
int a[maxn][maxn];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    int cost = 0;
    for(int i = 1; i <= m; ++i) {
        int cost1 = 0;
        int res1 = 0;
        int cost2 = 0;
        for(int j = 1; j <= n; ++j) {
            if(a[j][i] == 0) continue;
            int res2 = 0;
            for(int l = j; l <= min(n, j + k - 1); ++l) {
                res2 += a[l][i];
            }
            if(res2 > res1) {
                res1 = res2;
                cost1 = cost2;
            }
            cost2++;
        }
        ans += res1;
        cost += cost1;
        // printf("temp %d %d\n", res1, cost1);
    }
    printf("%d %d\n", ans, cost);
    return 0;
}
