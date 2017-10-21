#include <bits/stdc++.h>
using namespace std;
int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        double L, d;
        scanf("%lf%lf", &L, &d);
        double ans;
        if(L <= d) ans = 0;
        else ans = log(L / d) + 1;
        printf("%.6lf\n", ans);
    }
    return 0;
}
