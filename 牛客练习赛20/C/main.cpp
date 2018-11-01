#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int sign[maxn];
int sum[maxn];
int a, b, c, n;

void dfs(int u, int cnt) {
    if(sign[u] != 0) return;
    sum[cnt]++;
    sign[u] = cnt;
    dfs((a * u * u + b * u + c) % n, cnt);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &a, &b, &c, &n);
        memset(sum, 0, sizeof(sum));
        int cnt = 1;
        for(int i = 0; i < n; ++i) {
            dfs(i, cnt);
            cnt++;
            memset(sign, 0, sizeof(sign));
        }
        int ans = 0;
        for(int i = 0; i < maxn; ++i) {
            ans = max(ans, sum[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
