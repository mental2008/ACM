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
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;
int num[maxn];
LL n, m;

void init() {
    num[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        for(int j = i; j < maxn; j += i) {
            num[j]++;
        }
        num[i]++;
    }
}

double quick_pow(double x, LL ex) {
    double res = 1;
    double p = x;
    while(ex) {
        if(ex & 1) res = res * p;
        p *= p;
        ex >>= 1;
    }
    return res;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("data.txt", "w", stdout);
    init();
    while(~scanf("%lld%lld", &n, &m)) {
        if(m % 2 == 0) {
            for(int i = 1; i <= n; ++i) {
                printf("%.8lf", 0.5 - 0.5 * quick_pow((2 * num[i] - n) / (double)n, m));
                if(i == n) printf("\n");
                else printf(" ");
            }
        }
        else {
            for(int i = 1; i <= n; ++i) {
                printf("%.8lf", 0.5 * quick_pow((2 * num[i] - n) / (double)n, m) + 0.5);
                if(i == n) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
