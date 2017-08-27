#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
LL n;

LL quick_pow(LL x, LL ex) {
    LL res = 1;
    LL p = x % MOD;
    while(ex) {
        if(ex & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        ex >>= 1;
    }
    return res % MOD;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(~scanf("%lld", &n)) {
        if(n == 1) {
            printf("3 1\n");
            continue;
        }
        LL a = quick_pow(4, n - 1) % MOD;
        LL b = quick_pow(3, n - 2) % MOD;
        printf("%lld %lld\n", a, b);
    }
    return 0;
}

