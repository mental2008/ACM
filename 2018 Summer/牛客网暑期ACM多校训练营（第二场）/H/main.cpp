#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 400005;
int n;
LL val[maxn];
vector<int> G[maxn];
LL dp[maxn][3];
vector<int> temp;

void dfs(int u) {
    int len = (int)G[u].size();
    if(len == 1) {
        dp[u][0] = dp[u][1] = dp[u][2] = val[u];
        return;
    }
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        dp[u][0] = max(dp[u][0], dp[v][0] + val[u]);
    }
    temp.clear();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        temp.push_back(dp[v][0]);
    }
    sort(temp.begin(), temp.end());
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &val[i]);
    }
    for(int i = 0; i < n; ++i) G[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(dp, 0, sizeof(dp));
    dfs(1);
    return 0;
}
