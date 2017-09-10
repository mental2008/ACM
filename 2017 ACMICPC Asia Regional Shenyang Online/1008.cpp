#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL INF = 1e15;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 10005;
int n;
LL p[maxn];
struct Edge {
    int from, to;
    LL dis;
    Edge(int _from, int _to, LL _dis) {
        from = _from, to = _to, dis = _dis;
    }
};
vector<Edge> edges;
vector<int> G[maxn];
LL ans;

void AddEdge(int from, int to, LL dis) {
    edges.push_back(Edge(from, to, dis));
    edges.push_back(Edge(to, from, dis));
    int k = (int)edges.size();
    G[from].push_back(k - 2);
    G[to].push_back(k - 1);
}

void dfs(int u, int fa, LL MAX, LL MIN, LL cost1, LL cost2) {
    if(ans < -p[u] + MAX) ans = -p[u] + MAX;
    if(ans < p[u] - MIN) ans = p[u] - MIN;
    int len = (int)G[u].size();
    for(int i = 0; i < len; ++i) {
        Edge e = edges[G[u][i]];
        int v = e.to;
        if(fa != v) {

            dfs(v, u, max());
        }
    }
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        edges.clear();
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", &p[i]);
        }
        for(int i = 1; i < n; ++i) {
            int u, v;
            LL w;
            scanf("%d%d%lld", &u, &v, &w);
            AddEdge(u, v, w);
        }
        ans = 0;
        dfs(1, -1, -INF, INF, 0, 0);
    }
    return 0;
}
