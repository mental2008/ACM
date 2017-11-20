#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
    int m, n, x;
    int speed[105];
    int res[105];
    while(~scanf("%d%d%d", &m, &n, &x)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &speed[i]);
        sort(speed + 1, speed + 1 + n);
        mem(res, 0);
        int sum = m;
        int t = 0;
        while(t < x) {
            for(int i = 1; i <= n; ++i) {
                if(sum <= 0) continue;
                if(res[i] == 0) {
                    res[i] = speed[i];
                    sum--;
                }
            }
            int MIN = INF;
            for(int i = 1; i <= n; ++i) {
                if(res[i] == 0) continue;
                if(res[i] < MIN) {
                    MIN = res[i];
                }
            }
            if(MIN == INF) break;
            if(t + MIN >= x) MIN = x - t;
            for(int i = 1; i <= n; ++i) {
                if(res[i] == 0) continue;
                res[i] -= MIN;
            }
            t += MIN;
        }
        int temp = 0;
        for(int i = 1; i <= n; ++i) {
            if(res[i]) temp++;
        }
        printf("%d %d\n", sum, temp);
    }
    return 0;
}
