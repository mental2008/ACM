#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1005;
int n, r, l;
vector<int> G[maxn * 2];
bool mark[maxn * 2];
int S[maxn * 2], c;
int x[maxn], y[maxn];

bool dfs(int u) {
    if(mark[u ^ 1]) return false;
    if(mark[u]) return true;
    mark[u] = true;
    S[c++] = u;
    for(int i = 0; i < G[u].size(); ++i) {
        if(!dfs(G[u][i])) return false;
    }
    return true;
}

void init() {
    for(int i = 0; i < l * 2; ++i) G[i].clear();
    mem(mark, 0);
}

bool solve() {
    for(int i = 0; i < 2 * l; i += 2) {
        if(!mark[i] && !mark[i + 1]) {
            c = 0;
            if(!dfs(i)) {
                while(c > 0) mark[S[--c]] = false;
                if(!dfs(i + 1)) return false;
            }
        }
    }
    return true;
}

int main() {
    while(~scanf("%d%d%d", &n, &r, &l)) {
        for(int i = 0; i < l; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        init();
        for(int i = 0; i < l; ++i) {
            for(int j = i + 1; j < l; ++j) {
                if(x[i] == x[j] && abs(y[i] - y[j]) <= 2 * r) {
                    G[2 * i + 1].push_back(2 * j);
                    G[2 * j + 1].push_back(2 * i);
                }
                if(y[i] == y[j] && abs(x[i] - x[j]) <= 2 * r) {
                    G[2 * i].push_back(2 * j + 1);
                    G[2 * j].push_back(2 * i + 1);
                }
            }
        }
        bool ans = solve();
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
