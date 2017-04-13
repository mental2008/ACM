#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL n, q;

LL quick_add(LL origin, LL num) {
    LL res = 0;
    LL p = origin;
    while(num) {
        if(num & 1) {
            res = (res + p) % q;
        }
        p = (p + p) % q;
        num >>= 1;
    }
    return res;
}

LL quick_pow(LL num) {
    LL res = 1;
    LL p = 2;
    while(num) {
        if(num & 1) {
            res = quick_add(res, p);
        }
        p = quick_add(p, p);
        num >>= 1;
    }
    return res;
}

int main() {
    while(~scanf("%lld%lld", &n, &q)) {
        LL ans = quick_pow(n);
        ans = (ans + q - 2) % q;
        printf("%lld\n", ans);
    }
    return 0;
}