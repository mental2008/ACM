#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL a[55];
int n;
int main() {
    while(~scanf("%d", &n)) {
        LL MIN = INF;
        int minsign = -1;
        LL MAX = -INF;
        int maxsign = -1;
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            if(MIN > a[i]) {
                MIN = a[i];
                minsign = i;
            }
            if(MAX < a[i]) {
                MAX = a[i];
                maxsign = i;
            }
        }
        printf("%d\n", 2 * n - 1);
        if(abs(MIN) < abs(MAX)) {
            for(int i = 1; i <= n; ++i) {
                if(maxsign == i) continue;
                printf("%d %d\n", maxsign, i);
            }
            printf("%d %d\n", maxsign, maxsign);
            for(int i = 2; i <= n; ++i) {
                printf("%d %d\n", i - 1, i);
            }
        }
        else {
            for(int i = 1; i <= n; ++i) {
                if(minsign == i) continue;
                printf("%d %d\n", minsign, i);
            }
            printf("%d %d\n", minsign, minsign);
            for(int i = n; i > 1; --i) {
                printf("%d %d\n", i, i - 1);
            }
        }
    }
    return 0;
}
