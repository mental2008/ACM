#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

void extendGcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    else {
        extendGcd(b, a % b, x, y);
        LL tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        LL x, k;
        scanf("%lld%lld", &x, &k);
        LL x1, x2;
        if(x % k == 0) {
            x1 = x / k;
            x2 = x / k;
        }
        else {
            x1 = x / k;
            x2 = x / k + 1;
        }
        //cout << x1 << x2 << endl;
        LL Gcd = gcd(x1, x2);
        //cout << Gcd << endl;
        x1 /= Gcd;
        x2 /= Gcd;
        x /= Gcd;
        LL p, q;
        extendGcd(x1, x2, p, q);
        p *= x;
        q *= x;
        printf("%lld %lld\n", p, q);
    }
    return 0;
}