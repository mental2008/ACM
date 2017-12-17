#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-6;
const int maxn = 1e5 + 5;
LL n;
LL pre[15];
LL ten[12];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    pre[0] = 0;
    for(int i = 1; i <= 12; ++i) pre[i] = (pre[i - 1] * 10) + 9;
    ten[0] = 1;
    for(int i = 1; i <= 12; ++i) ten[i] = ten[i - 1] * 10;
    while(~scanf("%lld", &n)) {
        LL temp = n;
        int bit = 0;
        while(temp) {
            temp /= 10;
            bit++;
        }
        if(n <= 4) {
            printf("%lld\n", n * (n - 1) / 2);
            continue;
        }
        if(pre[bit] - n < n) {
            LL ans = (n - (pre[bit] - n) + 1) / 2;
            if(pre[bit] - n == 0) ans--;
            printf("%lld\n", ans);
        }
        else {
            LL ans = 0;
            for(int i = 1; i <= 9; ++i) {
                if(i * ten[bit - 1] + pre[bit - 1] <= n){
                    // LL temp = min((i * ten[bit - 1] + pre[bit - 1] - 1) / 2, i * ten[bit - 1] + pre[bit - 1] - ten[bit - 1] + 1);
                    // printf("i = %d temp = %lld %lld\n", i, temp, i * ten[bit - 1] + pre[bit - 1]);
                    ans += min(((i * ten[bit - 1] + pre[bit - 1] - 1) / 2), (i * ten[bit - 1] + pre[bit - 1] - ten[bit - 1] + 1));
                }
               else if(i * ten[bit - 1] + pre[bit - 1] - n < n) {
                    // LL temp = min((n - (i * ten[bit - 1] + pre[bit - 1] - n) + 1) / 2, (n - ten[bit - 1] + 1));
                    // printf("i = %d temp = %lld\n", i, temp);
                    ans += min((n - (i * ten[bit - 1] + pre[bit - 1] - n) + 1) / 2, (n - ten[bit - 1] + 1));
                }
            }
            ans += ((pre[bit - 1] - 1) / 2);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
