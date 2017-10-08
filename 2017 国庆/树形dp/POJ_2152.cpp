#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
int n;
vector<int> G[maxn];
vector<int> dis[maxn];
int cost[maxn];
int limit[maxn];
int d[maxn][maxn];
int root;
int best[maxn];
int dp[maxn][maxn];

void dfs_dis(int u, int fa) {
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        d[root][v] = d[root][u] + dis[u][i];
        dfs_dis(v, u);
    }
}

void solve(int u, int fa) {
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        solve(v, u);
    }
    for(int i = 1; i <= n; ++i) {
        if(d[u][i] > limit[u]) continue;
        dp[u][i] = cost[i];
        for(int j = 0; j < len; ++j) {
            int v = G[u][j];
            if(v == fa) continue;
            dp[u][i] += min(dp[v][i] - cost[i], best[v]);
        }
        best[u] = min(best[u], dp[u][i]);
    }
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            dis[i].clear();
        }
        for(int i = 1; i <= n; ++i) scanf("%d", &cost[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &limit[i]);
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            dis[u].push_back(w);
            dis[v].push_back(w);
        }
        for(int i = 1; i <= n; ++i) {
            root = i;
            d[root][root] = 0;
            dfs_dis(i, -1);
        }
        mem(dp, 0x3f);
        mem(best, 0x3f);
        solve(1, -1);
        printf("%d\n", best[1]);
    }
    return 0;
}
