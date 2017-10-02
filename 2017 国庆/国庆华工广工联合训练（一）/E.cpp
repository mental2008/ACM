#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n;
LL a[maxn];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        if(n == 1) {
            printf("%lld\n", a[1]);
        }
        else if(n % 2 == 0) {
            LL ans = 0;
            for(int i = 3; i < n; i += 2) {
                ans += min(a[i + 1] + 2 * a[2] + a[1], 2 * a[1] + a[i] + a[i + 1]);
            }
            ans += a[2];
            printf("%lld\n", ans);
        }
        else {
            LL ans = 0;
            for(int i = 4; i < n; i += 2) {
                ans += min(a[i + 1] + 2 * a[2] + a[1], 2 * a[1] + a[i] + a[i + 1]);
            }
            ans += a[1] + a[2] + a[3];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
