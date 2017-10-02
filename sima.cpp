#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 125005;
int M, S, T;
int dp[maxn];

int main() {
    while(~scanf("%d%d%d", &M, &S, &T)) {
        mem(dp, 0);
        for(int i = 1; i <= T; ++i) {
            if(M >= 10) {
                dp[i] = dp[i - 1] + 60;
                m -= 10;
            }
            else {
                if(M <= )
                dp[i] = dp[i - 1];
                m += 4;
            }
        }
        bool flag = false;
        for(int i = T; i <= T + 2; i ) {
            if(dp[T] >= S) {
                flag = true;
                break;
            }
        }
        if(flag == true) {
            puts("Yes");
            for(int i = 0; i <= T; ++i) {
                bool ok = false;
                for(int j = 0; j <= 10; ++j) {
                    if(dp[i][j] >= S) {
                        printf("%d\n", dp[i][j]);
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
        }
        else {
            puts("No");
            int ans = -1;
            for(int i = 0; i <= 10; ++i) ans = max(ans, dp[T][i]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
