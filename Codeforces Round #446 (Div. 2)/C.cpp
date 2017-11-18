#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2005;
int n;
LL a[maxn];

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

int main() {
    scanf("%d", &n);
    int one = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if(a[i] == 1) one++;
    }
    if(one) {
        printf("%d\n", n - one);
        return 0;
    }
    LL ans = INF;
    for(int i = 1; i <= n; ++i) {
        LL temp = a[i];
        for(int j = i; j <= n; ++j) {
            temp = gcd(temp, a[j]);
            if(temp == 1) {
                ans = min(ans, (LL)j - i);
            }
        }
    }
    printf("%lld\n", (ans == INF ? -1: ans + n - 1));
    return 0;
}
