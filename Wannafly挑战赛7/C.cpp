#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int main() {
    LL x, y;
    int q;
    while(~scanf("%lld%lld%d", &x, &y, &q)) {
        double p = q / 10000.0;
        double ans = 0;
        double pro = 1;
        int add = 1;
        while(1) {
            if(pro < 1e-15) break;
            ans += (((add * y) / x + (((add * y) % x == 0) ? 0 : 1)) * pro);
            pro *= (1 - p);
            add++;
        }
        printf("%.9lf\n", ans * p);
    }
    return 0;
}//枚举抽卡单数
