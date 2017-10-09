#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = (1e6 + 5) * 2;
int n, k;
int head[maxn];
int nxt[maxn];
int dis[maxn];
int to[maxn];
int cnt;
int dp[maxn][3];
int ans[maxn];
deque<int> d1, d2;

void AddEdge(int u, int v, int w) {
    dis[cnt] = w;
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int fa) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u);
        if(dp[v][0] + dis[i] > dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[v][0] + dis[i];
        }
        else if(dp[v][0] + dis[i] > dp[u][1]) {
            dp[u][1] = dp[v][0] + dis[i];
        }
    }
}

void dfs2(int u, int fa) {
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        if(dp[v][0] + dis[i] == dp[u][0]) {
            dp[v][2] = dp[u][1] + dis[i];
        }
        else {
            dp[v][2] = dp[u][0] + dis[i];
        }
        dp[v][2] = max(dp[v][2], dp[u][2] + dis[i]);
        dfs2(v, u);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    mem(head, -1);
    mem(nxt, 0);
    mem(to, 0);
    cnt = 0;
    for(int i = 2; i <= n; ++i) {
        int u, w;
        scanf("%d%d", &u, &w);
        AddEdge(u, i, w);
        AddEdge(i, u, w);
    }
    mem(dp, 0);
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; ++i) ans[i] = max(dp[i][0], dp[i][2]);
    int res = 0;
    d1.clear();
    d2.clear();
    for(int i = 1, j = 1; i <= n; ++i) {
        while(!d1.empty() && ans[d1.back()] <= ans[i]) d1.pop_back();
        while(!d2.empty() && ans[d2.back()] >= ans[i]) d2.pop_back();
        d1.push_back(i);
        d2.push_back(i);
        if(ans[d1.front()] - ans[d2.front()] > k) {
            j = min(d1.front(), d2.front()) + 1;
            while(!d1.empty() && d1.front() < j) d1.pop_front();
            while(!d2.empty() && d2.front() < j) d2.pop_front();
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);
    return 0;
}
