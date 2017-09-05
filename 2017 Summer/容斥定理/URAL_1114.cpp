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
const LL INF = 1e14;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
int n, a, b;
ULL dp[25][20][20];
int main() {
    mem(dp, 0);
    for(int i = 0; i <= 15; ++i) {
        for(int j = 0; j <= 15; ++j) {
            dp[0][i][j] = 1;
        }
    }
    for(int i = 1; i <= 20; ++i) {
        for(int j = 0; j <= 15; ++j) {
            for(int k = 0; k <= 15; ++k) {
                for(int p = 0; p <= j; ++p) {
                    for(int q = 0; q <= k; ++q) {
                        dp[i][j][k] += dp[i - 1][p][q];
                    }
                }
            }
        }
    }
    while(~scanf("%d%d%d", &n, &a, &b)) {
        printf("%llu\n", dp[n][a][b]);
    }
    return 0;
}//得用BigInteger
