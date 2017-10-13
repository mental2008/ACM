#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int n, k, x;
int a[105];
int main() {
    scanf("%d%d%d", &n, &k, &x);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = n; i >= max(1, n - k + 1); --i) {
        a[i] = x;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += a[i];
    }
    printf("%d\n", ans);
    return 0;
}
