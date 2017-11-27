#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 400;
int n;
int a[maxn];
int sum[maxn][maxn];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int MIN = INF;
        for(int i = 1; i <= n; ++i) {
            sum[i][i] = a[i];
            for(int j = i + 1; j <= n; ++j) {
                sum[i][j] = sum[i][j - 1] + a[j];
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                MIN = min(MIN, abs(360 - 2 * sum[i][j]));
            }
        }
        printf("%d\n", MIN);
    }
    return 0;
}
