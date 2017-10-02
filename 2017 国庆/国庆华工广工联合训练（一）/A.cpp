#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 5e4 + 5;
int n, m, k;
vector<int> vec[maxn];
int val[maxn];

bool dfs(int u) {
    int len = vec[u].size();
    bool ok;
    int temp;
    for(int i = 1; i <= k; ++i) {
        ok = true;
        for(int j = 0; j < len; ++j) {
            int v = vec[u][j];
            if(val[v] == i) {
                ok = false;
                break;
            }
        }
        if(ok) {
            temp = i;
            break;
        }
    }
    if(!ok) return false;
    val[u] = temp;
    for(int i = 0; i < len; ++i) {
        int v = vec[u][i];
        if(!val[v]) {
            if(!dfs(v)) return false;
        }
    }
    return true;
}

int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        for(int i = 0; i < maxn; ++i) vec[i].clear();
        for(int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        mem(val, 0);
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(!val[i]) {
                if(!dfs(i)) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            for(int i = 1; i <= n; ++i) {
                printf("%d\n", val[i]);
            }
        }
        else puts("-1");
    }
    return 0;
}
