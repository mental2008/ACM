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
const LL INF = 1e18;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
int n;
LL ans[505];
LL d[505][505];
int attack[505];
vector<int> alive;
bool vis[505];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        alive.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%lld", &d[i][j]);
            }
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &attack[i]);
        }
        for(int i = n; i >= 1; --i) {
            int len = (int)alive.size();
            mem(vis, 0);
            for(int j = 0; j < len; ++j) {
                int x;
                LL temp = INF;
                for(int k = 0; k < len; ++k) {
                    if(!vis[k] && d[attack[i]][alive[k]] <= temp) {
                        temp = d[attack[i]][alive[x = k]];
                    }
                }
                vis[x] = 1;
                for(int k = 0; k < len; ++k) {
                    if(d[attack[i]][alive[x]] + d[alive[x]][alive[k]] < d[attack[i]][alive[k]]) {
                        d[attack[i]][alive[k]] = d[attack[i]][alive[x]] + d[alive[x]][alive[k]];
                    }
                }
            }
            mem(vis, 0);
            for(int j = 0; j < len; ++j) {
                int x;
                LL temp = INF;
                for(int k = 0; k < len; ++k) {
                    if(!vis[k] && d[alive[k]][attack[i]] <= temp) {
                        temp = d[alive[x = k]][attack[i]];
                    }
                }
                vis[x] = 1;
                for(int k = 0; k < len; ++k) {
                    if(d[alive[x]][attack[i]] + d[alive[k]][alive[x]] < d[alive[k]][attack[i]]) {
                        d[alive[k]][attack[i]] = d[alive[x]][attack[i]] + d[alive[k]][alive[x]];
                    }
                }
            }
            for(int j = 0; j < len; ++j) {
                for(int k = 0; k < len; ++k) {
                        int a = alive[j];
                        int b = alive[k];
                        int c = attack[i];
                        if(d[a][b] > d[a][c] + d[c][b]) {
                            d[a][b] = d[a][c] + d[c][b];
                        }
                }
            }
            LL sum = 0;
            alive.push_back(attack[i]);
            len++;
            for(int j = 0; j < len; ++j) {
                for(int k = 0; k < len; ++k) {
                    int a = alive[j];
                    int b = alive[k];
                    sum += d[a][b];
                }
            }
            ans[i] = sum;
        }
        for(int i = 1; i <= n; ++i) {
            printf("%lld%c", ans[i], (i == n ? '\n' : ' '));
        }
    }
    return 0;
}
