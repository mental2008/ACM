#include <bits/stdc++.h>
#define LL long long
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 100005;
vector<int> G[maxn];
int n;
int node[maxn];
bool vis[maxn];
LL black;
LL white;

void dfs(int u, int color) {
    vis[u] = 1;
    if(color == -1) black++;
    else white++;
    int len = (int)G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(!vis[v]) {
            dfs(v, color * (-1));
        }
    }
}

int main() {
    while(~scanf("%d", &n)) {
        mem(vis, 0);
        black = white = 0;
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        LL ans = white * black - (n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
