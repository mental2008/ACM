#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, k;
vector<int> G[maxn];
int fa[maxn];
int st[maxn][25];
bool vis[maxn];

void dfs(int u, int fat) {
    fa[u] = fat;
    int len = (int)G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(fat == v) continue;
        dfs(v, u);
    }
}

void sgn(int u, int des) {
    vis[u] = 1;
    if(u == des) return;
    sgn(fa[u], des);
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(n, -1);
    for(int i = 1; i <= n; ++i) {
        st[i][0] = fa[i];
        for(int j = 1; j <= 20; ++j) {
            st[i][j] = -1;
        }
    }
    for(int j = 1; j <= 20; ++j) {
        for(int i = 1; i <= n; ++i) {
            int mid = st[i][j - 1];
            if(mid == -1) continue;
            st[i][j] = st[mid][j - 1];
        }
    }
    memset(vis, 0, sizeof(vis));
    vis[n] = 1;
    int sum = 1;
    for(int i = n - 1; i >= 1; --i) {
        if(vis[i]) continue;
        int res = i;
        int cnt = 0;
        for(int j = 20; j >= 0; --j) {
            if(st[res][j] == -1) continue;
            else if(!vis[st[res][j]]) {
                res = st[res][j];
                cnt += (1 << j);
            }
        }
        if(cnt + sum + 1 <= n - k) {
            sum += cnt + 1;
            sgn(i, res);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}
