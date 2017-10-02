#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
char s[55];
int dp[55];
int main() {
    while(~scanf("%s", s)) {
        mem(dp, 0);
        int len = strlen(s);
        int ans = 0;
        int Max;
        for(int i = 0; i < len; ++i) {
            Max = 0;
            for(int j = 0; j < i; ++j) {
                if(s[i] > s[j]) {
                    Max = max(Max, dp[j]);
                }
            }
            dp[i] = Max + 1;
            ans = max(ans, dp[i]);
        }
        printf("%d\n", 26 - ans);
    }
    return 0;
}
