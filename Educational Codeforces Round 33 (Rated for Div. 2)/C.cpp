#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n, m;
LL val[maxn];
int block[maxn];
int cnt;
LL ans[maxn];
vector<int> G[maxn];

void dfs(int u) {
    ans[cnt] = min(ans[cnt], val[u]);
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(block[v] == -1) {
            block[v] = cnt;
            dfs(v);
        }
    }
}

int main() {
    cnt = 0;
    mem(block, -1);
    mem(ans, 0x3f);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i) scanf("%lld", &val[i]);
    for(int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        if(block[i] == -1) {
            block[i] = cnt;
            dfs(i);
            cnt++;
        }
    }
    LL res = 0;
    for(int i = 0; i < cnt; ++i) {
        res += ans[i];
    }
    printf("%lld\n", res);
    return 0;
}
