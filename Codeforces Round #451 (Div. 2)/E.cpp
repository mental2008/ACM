#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int n;
LL a[maxn];
LL b[maxn];
int main() {
    while(~scanf("%d", &n)) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            LL val;
            scanf("%lld", &val);
            LL temp = sqrt(val);
            if(temp * temp == val) {
                a[i] = 0;
                cnt++;
                if(val == 0) b[i] = 2;
                else b[i] = 1;
            }
            else {
                b[i] = 0;
                a[i] = min(val - temp * temp, (temp + 1) * (temp + 1) - val);
            }
        }
        if(cnt >= (n / 2)) {
            sort(b + 1, b + 1 + n);
            LL ans = 0;
            for(int i = 1; i <= (n / 2); ++i) {
                ans += b[i];
            }
            printf("%lld\n", ans);
        }
        else {
            sort(a + 1, a + 1 + n);
            LL ans = 0;
            for(int i = 1; i <= (n / 2); ++i) {
                ans += a[i];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
