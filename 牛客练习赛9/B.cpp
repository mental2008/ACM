#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
vector<int> G[maxn];
int dp1[maxn];//MIN
int dp2[maxn];//MAX
int vis[maxn];
int ans;

int dfs(int u) {
    int len = G[u].size();
    int res = 1;
    dp1[u] = u;
    dp2[u] = u;
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        res += dfs(v);
        dp1[u] = min(dp1[u], dp1[v]);
        dp2[u] = max(dp2[u], dp2[v]);
    }
    if(dp2[u] - dp1[u] + 1 == res) {
        ans++;
    }
    return res;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        mem(vis, 0);
        int root = -1;
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            vis[v] = 1;
            G[u].push_back(v);
            if(vis[u] == 0) root = u;
        }
        fill(dp1 + 1, dp1 + n + 1, INF);
        fill(dp2 + 1, dp2 + n + 1, -INF);
        ans = 0;
        dfs(root);
        printf("%d\n", ans);
    }
    return 0;
}
