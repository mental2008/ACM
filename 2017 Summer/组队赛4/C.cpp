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
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);

int L, R, D, U;
int K, B1, B2;
int n;
int x[55];
int y[55];
int r[55];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d%d%d", &L, &R, &D, &U);
        scanf("%d%d%d", &K, &B1, &B2);
        if(B1 < B2) swap(B1, B2);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
        int sum = 0;
        int count = 0;
        for(double i = L; i <= R; i += 0.05) {
            for(double j = D; j <= U; j += 0.05) {
                count++;
                double xx = i;
                double yy = j;
                bool ok = true;
                if(yy >= K * xx + B2 && yy <= K * xx + B1) {
                    continue;
                }
                for(int k = 0; k < n; ++k) {
                    if((xx - x[k]) * (xx - x[k]) + (yy - y[k]) * (yy - y[k]) <= r[k] * r[k]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) sum++;
            }
        }
        double ans = (double)(sum) / count;
        ans *= 100;
        printf("%d", (int)(ans + 0.5));
        puts("%");
    }
    return 0;
}
