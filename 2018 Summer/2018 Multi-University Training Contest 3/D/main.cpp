#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 105;
int b[maxn];
int n, m;

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d%d", &val, &b[i]);
        }
        sort(b + 1, b + 1 + n);
        int ans = 0;
        LL res = 1;
        for(int i = 1; i <= n; ++i) {
            res = res * (1 + b[i]);
            if(res > m) break;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
