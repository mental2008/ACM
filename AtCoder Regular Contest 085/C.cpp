#include <bits/stdc++.h>
using namespace std;
const double exps = 1e-6;

double quick_pow(double x, int n) {
    double res = 1;
    double p = x;
    while(n) {
        if(n & 1) res *= p;
        p *= p;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        double ans = 0;
        int i = 1;
        while(1) {
            double temp = ((double)i * (1900 * m + (n - m) * 100) * quick_pow((1 - quick_pow(0.5, m)), i - 1) * quick_pow(0.5, m));
            ans += temp;
            if(fabs(temp) < exps) break;
            i++;
        }
        printf("%d\n", (int)(ans + 0.5));
    }
    return 0;
}
