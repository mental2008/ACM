#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL val[15][15];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j <= 9; ++j) {
            scanf("%lld", &val[i][j]);
        }
    }
    for(int k = 0; k <= 9; ++k) {
        for(int i = 0; i <= 9; ++i) {
            for(int j = 0; j <= 9; ++j) {
                val[i][j] = min(val[i][j], val[i][k] + val[k][j]);
            }
        }
    }
    LL sum = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int res;
            scanf("%d", &res);
            if(res != -1) {
                sum += val[res][1];
            }
        }
    }
    printf("%lld\n", sum);
    return 0;
}
