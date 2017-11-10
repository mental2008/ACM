#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int n, k;
int temp[5] = {0, 0, 1, 2, 9};

LL C(int x, int y) {
    LL res1 = 1, res2 = 1;
    int cnt = 1;
    while(cnt <= y) {
        res1 *= (x - cnt + 1);
        res2 *= (y - cnt + 1);
        cnt++;
    }
    return res1 / res2;
}

int main() {
    while(~scanf("%d%d", &n, &k)) {
        LL ans = 1;
        for(int i = 2; i <= k; ++i) {
            ans += (C(n, i) * temp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
