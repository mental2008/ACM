#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
int n;
int a[maxn];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for(int i = 2; i < n; ++i) {
            if(a[i - 1] < a[i] && a[i] > a[i + 1]) ans++;
            else if(a[i - 1] > a[i] && a[i] < a[i + 1]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
