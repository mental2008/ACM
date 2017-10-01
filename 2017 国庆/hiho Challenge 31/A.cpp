#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n, k;
LL c[maxn];
LL ans[maxn];
int main() {
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &c[i]);
        }
        sort(c + 1, c + 1 + n);
        mem(ans, 0);
        for(int i = 0; i < n - 1; ++i) {
            ans[i] = c[i + 2] - c[i + 1];
        }
        sort(ans, ans + n - 1);
        LL res = 0;
        for(int i = k; i < n; ++i) {
            res += ans[i - k];
        }
        printf("%lld\n", res);
    }
    return 0;
}
