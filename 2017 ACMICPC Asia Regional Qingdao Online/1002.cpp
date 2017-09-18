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
LL p;
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%lld", &p);
        bool ok = false;
        for(LL i = 1; i < 1000100; ++i) {
            LL x = (i + 1LL) * (i + 1LL) + (i * i) + (i + 1LL) * i;
            if(x == p) {
                ok = true;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
