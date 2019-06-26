#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = sqrt(abs(a[1] - a[n]));
        printf("%d\n", ans);
    }
    return 0;
}
