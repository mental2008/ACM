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
LL x[3], y[3];
int main() {
    while(~scanf("%lld%lld%lld%lld%lld%lld", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2])) {
        LL res1 = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
        LL res2 = (x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2]);
        if(res1 == res2) {
            if((y[0] - y[1]) * (x[1] - x[2]) == (x[0] - x[1]) * (y[1] - y[2])) puts("No");
            else puts("Yes");
        }
        else puts("No");
    }
    return 0;
}
