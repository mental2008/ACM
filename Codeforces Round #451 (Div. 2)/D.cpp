#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
int n, m, k;
LL a[maxn];
int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        mem(a, 0);
        for(int i = 1; i <= n; ++i) {
            LL val;
            scanf("%lld", &val);
            a[val]++;
        }
        LL ans = 0;
        LL now = 0;
        for(int i = 0; i <= 1000000; ++i) {
            if(i - m >= 0) now -= a[i - m];
            if(now < 0) now = 0;
            now += a[i];
            if(now >= k) {
                ans += (now - k + 1);
                a[i] -= (now - k + 1);
                now = k - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
