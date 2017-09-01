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
const int maxn = 105;
int n;
int a[maxn][maxn];
bool vis[maxn][maxn];
int MIN, MAX;
int p[4] = {1, -1, 0, 0};
int q[4] = {0, 0, 1, -1};

void dfs(int x, int y, int lower, int upper) {
    for(int i = 0; i < 4; ++i) {
        int xx = p[i] + x;
        int yy = q[i] + y;
        if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
        if(vis[xx][yy]) continue;
        vis[xx][yy] = 1;
        if(a[xx][yy] >= lower && a[xx][yy] <= upper) {
            dfs(xx, yy, lower, upper);
        }
    }
    return;
}

bool judge(int limit) {
    for(int i = MIN; i + limit <= MAX; ++i) {
        mem(vis, 0);
        int lower = i;
        int upper = i + limit;
        if(a[1][1] < lower || a[1][1] > upper) continue;
        if(a[n][n] < lower || a[n][n] > upper) continue;
        vis[1][1] = 1;
        dfs(1, 1, lower, upper);
        if(vis[n][n]) return true;
    }
    return false;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        scanf("%d", &n);
        MIN = 200, MAX = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                if(MAX < a[i][j]) MAX = a[i][j];
                if(MIN > a[i][j]) MIN = a[i][j];
            }
        }
        int l = abs(a[1][1] - a[n][n]), r = MAX - MIN;
        int ans = 200;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(judge(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
