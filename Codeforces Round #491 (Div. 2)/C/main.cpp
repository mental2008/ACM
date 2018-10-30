#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;

bool solve(LL x) {
    LL res = n;
    LL a = 0;
    while(res) {
        if(res >= x) {
            a += x;
            res -= x;
        }
        else {
            a += res;
            res = 0;
        }
        res = res - res / 10;
    }
    if(a * 2 >= n) return true;
    return false;
}

int main()
{
    scanf("%lld", &n);
    LL l = 1, r = n;
    LL ans = r;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(solve(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
