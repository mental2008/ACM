#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, r;
    while(~scanf("%d%d", &k, &r)) {
        double ans = 0;
        for(int i = 1; (1 << i) - 1 <= (1 << k) - r; ++i) {
            double p = 1.0;
            int a = (1 << k) - 1;
            int b = (1 << i) - 1;
            int c = (1 << k) - r;
            for(; b >= 1; --b, --a, --c) {
                p = p * c / a;
            }
            ans += p;
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}
