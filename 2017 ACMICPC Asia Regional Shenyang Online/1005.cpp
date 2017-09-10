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
const LL MOD = 998244353;
const double exps = 1e-8;
const double PI = acos(-1.0);

struct mat {
    LL a[2][2];
};

mat mat_mul(mat x, mat y) {
    mat res;
    mem(res.a, 0);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
    return res;
}

LL mat_pow(LL n) {
    mat c, res;
    c.a[0][0] = c.a[0][1] = c.a[1][0] = 1;
    c.a[1][1] = 0;
    mem(res.a, 0);
    for(int i = 0 ; i < 2 ; i++) res.a[i][i] = 1;
    while(n) {
        if(n & 1) res = mat_mul(res, c);
        c = mat_mul(c, c);
        n >>= 1;
    }
    return (res.a[0][1] % MOD + MOD) % MOD;
}

int main() {
    LL k;
    while(~scanf("%lld", &k)) {
        k++;
        printf("%lld\n", ((mat_pow(2 * k + 1) - 1) % MOD + MOD) % MOD);
    }
    return 0;
}
