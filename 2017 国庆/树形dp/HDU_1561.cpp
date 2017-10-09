#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
#define interesting int
using namespace std;
const int maxn = 205;
int n, m;
int head[maxn];
int nxt[maxn];
int to[maxn];
int val[maxn];
int cnt;
int dp[maxn][maxn];

void init() {
    mem(head, -1);
    mem(nxt, -1);
    mem(to, 0);
    mem(dp, 0);
    mem(val, 0);
    cnt = 0;
}

void AddEdge(int u, int v) {
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int u, int num) {
    dp[u][1] = val[u];
    if(num == 1) return;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        dfs(v, num - 1);
        for(int j = num; j >= 1; --j) {
            for(int k = 1; k < j; ++k) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) break;
        init();
        for(int i = 1; i <= n; ++i) {
            int u, w;
            scanf("%d%d", &u, &w);
            AddEdge(u, i);
            val[i] = w;
        }
        dfs(0, m + 1);
        printf("%d\n", dp[0][m + 1]);
    }
    return 0;
}
