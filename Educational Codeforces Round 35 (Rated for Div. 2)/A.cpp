#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        int MIN = 0x3f3f3f3f;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            MIN = min(MIN, a[i]);
        }
        int ans = 0x3f3f3f3f;
        int last = -1;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == MIN) {
                if(last != -1) {
                    ans = min(i - last, ans);
                }
                last = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
