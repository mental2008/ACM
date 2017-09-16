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
const LL MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
ULL n;
ULL bits[80];
int main() {
    while(~scanf("%llu", &n)) {
        mem(bits, 0);
        ULL two = 1;
        int index = 0;
        while(1) {
            ULL temp = n / (2 * two);
            bits[index] = two * temp + n % two;
            index++;
            two *= 2;
            if(temp == 0) break;
        }
        ULL ans = 0;
        two = 1;
        for(int i = 0; i < index; ++i) {
            if(((n - 1) >> i) & 1) {
                ans = (ans + two % MOD * (n - 1 - bits[i]) % MOD) % MOD;
            }
            else {
                ans = (ans + two % MOD * bits[i] % MOD) % MOD;
            }
            two = (two * 2) % MOD;
        }
        printf("%llu\n", (ans % MOD + MOD) % MOD);
    }
    return 0;
}
