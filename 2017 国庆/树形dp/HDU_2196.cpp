#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 10005;
int n;
vector<int> G[maxn];
vector<int> dis[maxn];
int dp[maxn][3];

void dfs1(int u, int fa) {
    int len = G[u].size();
    if(len == 0) {
        dp[u][0] = dp[u][1] = 0;
        return;
    }
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        int w = dis[u][i];
        if(v == fa) continue;
        dfs1(v, u);
        if(dp[v][0] + w >= dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[v][0] + w;
        }
        else if(dp[v][0] + w >= dp[u][1]) {
            dp[u][1] = dp[v][0] + w;
        }
    }
}

void dfs2(int u, int fa) {
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        int w = dis[u][i];
        if(v == fa) continue;
        if(dp[v][0] + w == dp[u][0]) {
            dp[v][2] = w + dp[u][1];
        }
        else {
            dp[v][2] = w + dp[u][0];
        }
        dp[v][2] = max(dp[v][2], w + dp[u][2]);
        dfs2(v, u);
    }
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            dis[i].clear();
        }
        for(int i = 2; i <= n; ++i) {
            int u, w;
            scanf("%d%d", &u, &w);
            G[i].push_back(u);
            dis[i].push_back(w);
            G[u].push_back(i);
            dis[u].push_back(w);
        }
        mem(dp, 0);
        dfs1(1, -1);
        dfs2(1, -1);
        for(int i = 1; i <= n; ++i) {
            printf("%d\n", max(dp[i][0], dp[i][2]));
        }
    }
    return 0;
}
