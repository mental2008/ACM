#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e4 + 5;
int n;
int a[15];
double p[15];
double pi[15][maxn];

double quick_pow(double x, int num) {
    double res = 1;
    double temp = x;
    while(num) {
        if(num & 1) res *= temp;
        temp *= temp;
        num >>= 1;
    }
    return res;
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%lf", &a[i], &p[i]);
            pi[i][0] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < maxn; ++j) {
                pi[i][j] = pi[i][j - 1] * p[i];
            }
        }
        if(n == 1) {
            printf("%.6lf\n", 1.000);
            continue;
        }
        for(int i = 1; i <= n; ++i) {
            double ans = 0;
            for(int j = 1; j < maxn - 1; ++j) {
                double res = 1;
                for(int k = 1; k <= n; ++k) {
                    if(k == i) res *= (quick_pow(1 - pi[i][j + 1], a[i]) - quick_pow(1 - pi[i][j], a[i]));
                    else res *= quick_pow(1 - pi[k][j], a[k]);
                }
                ans += res;
            }
            printf("%.6lf%c", ans, (i == n ? '\n' : ' '));
        }
    }
    return 0;
}
