#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1505;
int n;
int a[maxn];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        bool ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if(a[i] > a[j]) ans = !ans;
            }
        }
        int m;
        scanf("%d", &m);
        while(m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int len = r - l + 1;
            int res = len * (len - 1) / 2;
            if(res % 2 == 1) ans = (!ans);
            if(ans) puts("odd");
            else puts("even");
        }
    }
    return 0;
}
