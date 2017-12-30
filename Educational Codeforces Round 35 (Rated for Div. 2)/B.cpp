#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, a, b;
    while(~scanf("%d%d%d", &n, &a, &b)) {
        int ans = -1;
        for(int i = 1; i < n; ++i) {
            if((i > a) || ((n - i) > b)) continue;
            int res = min(a / i, b / (n - i));
            ans = max(res, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
