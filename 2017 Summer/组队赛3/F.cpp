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
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 55;
int n, m;
vector<int> G[maxn];
double dp[55][105];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < maxn; ++i) G[i].clear();
        for(int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int q;
        scanf("%d", &q);
        while(q--) {
            int u, v, step;
            scanf("%d%d%d", &u, &v, &step);
            if(u == v) puts("1.00000000");
            else {
                for(int i = 1; i <= n; ++i) {
                    int len = G[i].size();
                    int sumv = 0;
                    for(int j = 0; j < len; ++j) {
                        if(G[i][j] == v) {
                            sumv++;
                        }
                    }
                    dp[i][1] = (double)(len - sumv) / len;
                }
                for(int i = 2; i <= step; ++i) {
                    for(int j = 1; j <= n; ++j) {
                        if(j == v) continue;
                        int len = G[j].size();
                        dp[j][i] = 0;
                        for(int k = 0; k < len; ++k) {
                            if(G[j][k] != v) {
                                dp[j][i] += (1.0 / len * dp[G[j][k]][i - 1]);
                            }
                        }
                    }
                }
                printf("%.8lf\n", 1 - dp[u][step]);
            }
        }
    }
    return 0;
}
