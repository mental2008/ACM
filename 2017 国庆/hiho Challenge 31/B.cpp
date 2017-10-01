#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
int n;
LL a[65];
int res[65][65][65];
bool vis[65];

struct Node {
    int x, y, z;
} node[65 * 65 * 65];
int cnt;

LL dfs(int pre, int now, int next, int depth) {
    if(depth == n - 2) {
        return 1;
    }
    LL ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(res[now][next][i] && !vis[i]) {
            vis[i] = 1;
            ans = (ans + dfs(now, next, i, depth + 1)) % MOD;
            vis[i] = 0;
        }
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        mem(res, 0);
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                for(int k = 1; k <= n; ++k) {
                    if(i == j || i == k || j == k) continue;
                    if(a[i] - a[j] >= a[j] - a[k]) {
                        res[i][j][k] = 1;
                        node[cnt].x = i;
                        node[cnt].y = j;
                        node[cnt++].z = k;
                    }
                }
            }
        }
        LL ans = 0;
        for(int i = 0; i < cnt; ++i) {
            mem(vis, 0);
            int x = node[i].x, y = node[i].y, z = node[i].z;
            vis[x] = vis[y] = vis[z] = 1;
            ans = (ans + dfs(x, y, z, 1)) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
