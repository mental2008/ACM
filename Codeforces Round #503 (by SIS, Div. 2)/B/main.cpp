#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
int p[maxn];
bool vis[maxn];

int dfs(int u) {
    if(vis[u]) return u;
    vis[u] = 1;
    return dfs(p[u]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);
        p[i] = v;
    }
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        int ans = dfs(i);
        printf("%d%c", ans, (i == n ? '\n' : ' '));
    }
    return 0;
}
