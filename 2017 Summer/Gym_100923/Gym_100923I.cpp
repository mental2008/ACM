#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int n;
int main() {
    freopen("perechi3.in", "r", stdin);
    freopen("perechi3.out", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        LL ans = 0;
        int m = sqrt(n);
        for(int i = 1; i <= m; ++i) {
            ans += 2 * (n / i);
        }
        ans -= m * m;
        printf("%lld\n", ans);
    }
    return 0;
}
