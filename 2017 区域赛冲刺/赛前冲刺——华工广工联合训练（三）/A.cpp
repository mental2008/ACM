#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n;
        LL ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            ans += (a * b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
