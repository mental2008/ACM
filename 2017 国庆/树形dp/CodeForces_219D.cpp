#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int head[maxn];
int to[maxn << 1];
int nxt[maxn << 1];
int dis[maxn << 1];
int cnt;
int n;
int dp1[maxn];
int dp2[maxn];

void init() {
    mem(head, -1);
    mem(nxt, -1);
    mem(dis, 0);
    mem(to, 0);
    cnt = 0;
}

void AddEdge(int u, int v, int w) {
    dis[cnt] = w;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int fa) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        int w = dis[i];
        if(v == fa) continue;
        dfs1(v, u);
        if(w == -1) dp1[u] += (1 + dp1[v]);
        else dp1[u] += dp1[v];
    }
}

void dfs2(int u, int fa) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        int w = dis[i];
        if(v == fa) continue;
        if(w == 1) {
            dp2[v] = dp1[u] - dp1[v] + 1 + dp2[u];
        }
        else {
            dp2[v] = dp1[u] - 1 - dp1[v] + dp2[u];
        }
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    init();
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        AddEdge(u, v, 1);
        AddEdge(v, u, -1);
    }
    mem(dp1, 0);
    mem(dp2, 0);
    dfs1(1, -1);
    dfs2(1, -1);
    int MIN = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i) {
        int temp = dp1[i] + dp2[i];
        if(MIN > temp) MIN = temp;
    }
    printf("%d\n", MIN);
    for(int i = 1; i <= n; ++i) {
        int temp = dp1[i] + dp2[i];
        if(MIN == temp) printf("%d ", i);
    }
    puts("");
    return 0;
}
