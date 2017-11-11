#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int a[maxn];
int n, z, w;
int main() {
    while(~scanf("%d%d%d", &n, &z, &w)) {
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans;
        if(n == 1) ans = abs(a[n] - w);
        else ans = max(abs(a[n] - w), abs(a[n] - a[n - 1]));
        printf("%d\n", ans);
    }
    return 0;
}
