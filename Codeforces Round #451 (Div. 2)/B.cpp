#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        LL r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

int main() {
    LL a, b, n;
    scanf("%lld%lld%lld", &n, &a, &b);
    LL Gcd = gcd(a, b);
    if(n % Gcd == 0) {
        LL x, y;
        a /= Gcd;
        b /= Gcd;
        n /= Gcd;
        extend_gcd(a, b, x, y);
        x *= n;
        y *= n;
        // printf("%lld %lld\n", x, y);
        LL upp = floor((double)x / b);
        LL low = ceil(-(double)y / a);
        // printf("%lld %lld %lld\n", a, b, n);
        // printf("upp = %lld\n", upp);
        // printf("low = %lld\n", low);
        if(upp >= low) {
            x = x - b * low;
            y = y + a * low;
            printf("YES\n%lld %lld\n", x, y);
        }
        else puts("NO");
    }
    else puts("NO");
    return 0;
}
