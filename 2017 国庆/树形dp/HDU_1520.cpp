#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 6005;
int n;
int val[maxn];
vector<int> G[maxn];
int dp[maxn][2];

void dfs(int u, int fa) {
    int len = G[u].size();
    if(len == 0) {
        dp[u][1] = val[u];
        dp[u][0] = 0;
        return;
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa) continue;
        dfs(v, u);
        sum1 += dp[v][0];
        sum2 += max(dp[v][1], dp[v][0]);
    }
    dp[u][1] = sum1 + val[u];
    dp[u][0] = sum2;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
        }
        while(1) {
            int u, v;
            scanf("%d%d", &u, &v);
            if(u == 0 && v == 0) break;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        mem(dp, 0);
        dfs(1, -1);
        printf("%d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}
