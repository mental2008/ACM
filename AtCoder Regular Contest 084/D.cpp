#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int k;
struct Node {
    int u, d;
    bool operator < (const Node& e) const {
        return d > e.d;
    }
};
priority_queue<Node> Q;
bool vis[maxn];
int d[maxn];

int dijkstra() {
    mem(vis, 0);
    fill(d, d + k, INF);
    while(!Q.empty()) Q.pop();
    d[1] = 1;
    Q.push((Node){1, 1});
    while(!Q.empty()) {
        Node x = Q.top();
        Q.pop();
        printf("%d %d\n", x.u, x.d);
        int u = x.u;
        if(u == 0) return x.d;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < 7; ++i) {
            int v = (u * 10) % k;
            if(vis[v]) continue;
            if(d[v] > d[u]) {
                d[v] = d[u];
                Q.push((Node){v, d[v]});
            }
        }
        if(d[(u + 1) % k] > d[u] + 1) {
            d[(u + 1) % k] = d[u] + 1;
            if(!vis[(u + 1) % k]) {
                Q.push((Node){(u + 1) % k, d[(u + 1) % k]});
            }
        }
    }
    return -1;
}

int main() {
    while(~scanf("%d", &k)) {
        int ans = dijkstra();
        printf("%d\n", ans);
    }
    return 0;
}
