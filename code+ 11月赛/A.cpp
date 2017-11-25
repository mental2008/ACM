#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

LL lcm(LL x, LL y) {
    return x / gcd(x, y) * y;
}

int main() {
    LL a, b, c;
    while(~scanf("%lld%lld%lld", &a, &b, &c)) {
        LL temp = lcm(a, b);
        temp = lcm(temp, c);
        printf("%lld\n", temp);
    }
    return 0;
}
