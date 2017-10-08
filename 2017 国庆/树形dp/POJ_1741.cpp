#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 10005;
vector<int> G[maxn];
vector<int> dis[maxn];
vector<int> dep;
int n, k;
int son[maxn];
int f[maxn];
int root;
int ans;
int size;
bool done[maxn];
int d[maxn];

void getRoot(int u, int fa) {
    son[u] = 1;
    f[u] = 0;
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa || done[v]) continue;
        getRoot(v, u);
        son[u] += son[v];
        f[u] = max(f[u], son[v]);
    }
    f[u] = max(f[u], size - son[u]);
    if(f[u] < f[root]) root = u;
}

void getDepth(int u, int fa) {
    dep.push_back(d[u]);
    son[u] = 1;
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(v == fa || done[v]) continue;
        d[v] = d[u] + dis[u][i];
        getDepth(v, u);
        son[u] += son[v];
    }
}

int calc(int u, int init) {
    dep.clear();
    d[u] = init;
    getDepth(u, 0);
    sort(dep.begin(), dep.end());
    int res = 0;
    for(int l = 0, r = dep.size() - 1; l < r;) {
        if(dep[l] + dep[r] <= k) {
            res += (r - l);
            l++;
        }
        else r--;
    }
    return res;
}

void solve(int u) {
    ans += calc(u, 0);
    done[u] = 1;
    int len = G[u].size();
    for(int i = 0; i < len; ++i) {
        int v = G[u][i];
        if(done[v]) continue;
        ans -= calc(v, dis[u][i]);
        f[0] = size = son[v];
        root = 0;
        getRoot(v, -1);
        solve(root);
    }
}

int main() {
    while(~scanf("%d%d", &n, &k), n || k) {
        mem(done, 0);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            dis[i].clear();
        }
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(v);
            G[v].push_back(u);
            dis[u].push_back(w);
            dis[v].push_back(w);
        }
        root = 0;
        f[0] = size = n;
        getRoot(1, -1);
        ans = 0;
        solve(root);
        printf("%d\n", ans);
    }
    return 0;
}
