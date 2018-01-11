#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL solve(LL n, LL m, LL k) {
    if(n == 0 || m == 0) return 0;
    else if(k > n || k > m) return -1;
    else {
        LL x;
        if(n % k == 0) x = n / k;
        else x = n / k + 1;
        LL y;
        if(m % k == 0) y = m / k;
        else y = m / k + 1;
        return x * y;
    }
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        LL n, m, r, c, k;
        scanf("%lld%lld%lld%lld%lld", &n, &m, &r, &c, &k);
        LL res1 = solve(r - 1, c - 1, k);
        LL res2 = solve(n - r, m - c, k);
        LL res3 = solve(r - 1, m - c, k);
        LL res4 = solve(n - r, c - 1, k);
        if(res1 == -1 || res2 == -1 || res3 == -1 || res4 == -1) {
            puts("-1");
        }
        else {
            LL ans = res1 + res2 + res3 + res4;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
