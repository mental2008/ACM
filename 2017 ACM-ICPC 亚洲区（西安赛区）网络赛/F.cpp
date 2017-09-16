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
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
using namespace std;
LL n, m;

LL quick_pow(LL x, LL n) {
    LL res = 1;
    LL p = x % MOD;
    while(n) {
        if(n & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        n >>= 1;
    }
    return res % MOD;
}

int main() {
    while(~scanf("%lld%lld", &n, &m)) {
        if(m == 0) {
            switch(n % 4) {
                case 0:
                    puts("1");
                    break;
                case 1:
                    puts("0");
                    break;
                case 2:
                    puts("998244352");
                    break;
                case 3:
                    puts("0");
                default:
                    break;
            }
        }
        else {
            if(n % 2 == 0) {
                int val = m % 4;
                if(val == 1 || val == 3) puts("0");
                else {
                    LL temp = 1;
                    for(int i = 1; i <= m; ++i) {
                        temp = (temp * i) % MOD;
                    }
                    LL res = quick_pow(n, m);
                    temp = quick_pow(temp, MOD - 2);
                    res = val * res % MOD * temp % MOD;
                    res = (res % MOD + MOD) % MOD;
                    printf("%lld\n", res);
                }
            }
            else {
                int val = m % 4;
                if(val == 0 || val == 2) puts("0");
                else {
                    LL temp = 1;
                    for(int i = 1; i <= m; ++i) {
                        temp = (temp * i) % MOD;
                    }
                    LL res = quick_pow(n, m);
                    temp = quick_pow(temp, MOD - 2);
                    res = val * res % MOD * temp % MOD;
                    res = (res % MOD + MOD) % MOD;
                    printf("%lld\n", res);
                }
            }
        }
    }
}
