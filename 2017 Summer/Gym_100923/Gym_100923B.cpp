#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
const LL INF = 1e12;
struct Edge {
    int from, to, cost, sign;
    Edge(int _from, int _to, int _cost, int _sign) {
        from = _from, to = _to, cost = _cost, sign = _sign;
    }
};
vector<Edge> edges;
vector<int> G[maxn];
LL d[maxn];
bool vis[maxn];
int cnt;
bool done[maxn];
int n, m;
int fam[maxn];

struct HeapNode {
    LL d;
    int u;
    bool operator < (const HeapNode &e) const {
        return d > e.d;
    }
};

priority_queue<HeapNode> q;

void init() {
    for(int i = 0; i < maxn; ++i) G[i].clear();
    edges.clear();
    mem(done, 0);
    mem(fam, 0);
    cnt = 0;
    while(!q.empty()) q.pop();
}

void AddEdge(int from, int to, int cost, int sign) {
    edges.push_back(Edge(from, to, cost, sign));
    int k = (int)edges.size();
    G[from].push_back(k - 1);
}

void dijstra() {
    for(int i = 2; i <= n; ++i) d[i] = INF;
    mem(vis, 0);
    d[1] = 0;
    q.push((HeapNode){0, 1});
    while(!q.empty()) {
        HeapNode x = q.top();
        q.pop();
        int u = x.u;
        if(vis[u]) continue;
        else vis[u] = 1;
        for(int i = 0; i < (int)G[u].size(); ++i) {
            Edge e = edges[G[u][i]];
            if(d[e.to] > d[u] + (LL)e.cost) {
                d[e.to] = d[u] + (LL)e.cost;
                done[fam[e.to]] = 0;
                fam[e.to] = e.sign;
                done[e.sign] = 1;
                q.push((HeapNode){d[e.to], e.to});
            }
        }
    }
}

void dfs(int u) {
    for(int i = 0; i < (int)G[u].size(); ++i) {
        Edge e = edges[G[u][i]];
        if(done[e.sign]) {
            ++cnt;
            printf("%d", e.sign);
            if(cnt != m) printf(" ");
            else puts("");
            dfs(e.to);
        }
    }
}

int main() {
    freopen("algoritm.in", "r", stdin);
    freopen("algoritm.out", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d\n", &n, &m);
        init();
        for(int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w, i);
        }
        dijstra();
        dfs(1);
        for(int i = 1; i <= m; ++i) {
            if(!done[i]) {
                ++cnt;
                printf("%d", i);
                if(cnt != m) printf(" ");
                else puts("");
            }
        }
    }
    return 0;
}
