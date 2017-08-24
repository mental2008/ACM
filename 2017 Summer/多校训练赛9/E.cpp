#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
int n, m;
struct Edge {
    int from, to;
    Edge(int _from, int _to) {
        from = _from, to = _to;
    }
};
vector<Edge> edges;
vector<int> G[maxn];
int dfs_clock;
int scc_cnt;
int lowlink[maxn];
int pre[maxn];
stack<int> s;
int sccno[maxn];
vector<int> vec[maxn];
bool vis[maxn];
int degree[maxn];

void init() {
    for(int i = 0; i < maxn; ++i) G[i].clear();
    edges.clear();
    dfs_clock = scc_cnt = 0;
    mem(lowlink, 0);
    mem(pre, 0);
    mem(sccno, 0);
    for(int i = 0; i < maxn; ++i) vec[i].clear();
    while(!s.empty()) s.pop();
    mem(degree, 0);
}

void AddEdge(int from, int to) {
    edges.push_back(Edge(from, to));
    int k = (int)edges.size();
    G[from].push_back(k - 1);
}

void dfs(int u) {
    lowlink[u] = pre[u] = ++dfs_clock;
    s.push(u);
    for(int i = 0; i < (int)G[u].size(); ++i) {
        int v = edges[G[u][i]].to;
        if(!pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if(!sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if(lowlink[u] == pre[u]) {
        scc_cnt++;
        while(1) {
            int x = s.top();
            s.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

bool dfs1(int u, int sum) {
    if(sum == scc_cnt) return true;
    int len = (int)vec[u].size();
    for(int i = 0; i < len; ++i) {
        int v = vec[u][i];
        if(vis[v]) continue;
        vis[v] = 1;
        if(dfs1(v, sum + 1)) return true;
        vis[v] = 0;
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d%d", &n, &m);
        init();
        for(int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            AddEdge(u, v);
        }
        for(int i = 1; i <= n; ++i) {
            if(!pre[i]) {
                dfs(i);
            }
        }
        for(int i = 0; i < (int)edges.size(); ++i) {
            int u = edges[i].from;
            int v = edges[i].to;
            if(sccno[u] != sccno[v]) {
                vec[sccno[u]].push_back(sccno[v]);
                degree[sccno[v]]++;
            }
        }
        mem(vis, 0);
        int root;
        for(int i = 1; i <= scc_cnt; ++i) {
            if(degree[i] == 0) {
                root = i;
                break;
            }
        }
        vis[root] = 1;
        if(dfs1(root, 1)) puts("I love you my love and our love save us!");
        else puts("Light my fire!");
    }
    return 0;
}
