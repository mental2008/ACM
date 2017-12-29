#include <cstdio>
typedef long long LL;
int main() {
    LL n;
    while(~scanf("%lld", &n)) {
        LL ans = (n / 3) * 2;
        n %= 3;
        if(n) ans++;
        printf("%lld\n", ans);
    }
    return 0;
}
