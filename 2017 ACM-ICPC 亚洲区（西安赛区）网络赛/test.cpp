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
ULL n;
int main() {
    while(~scanf("%llu", &n)) {
        ULL ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            ans = (ans + min(1ULL * i, (i ^ (n - 1))) % MOD) % MOD;
        }
        printf("%llu\n", (ans + n - 1) % MOD);
    }
    return 0;
}
