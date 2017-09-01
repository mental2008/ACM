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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 205;
int n, k;
bool vis[maxn];
struct Node {
    int five, two;
    bool operator < (const Node& e) const {
        return five > e.five;
    }
} node[maxn];
int dp[maxn][maxn][3];
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 1; i <= n; ++i) {
            LL val;
            scanf("%lld", &val);
            node[i].five = node[i].two = 0;
            while(val % 5 == 0) {
                node[i].five++;
                val /= 5;
            }
            while(val % 2 == 0) {
                node[i].two++;
                val /= 2;
            }
        }
        mem(dp, 0);
        for(int i = 1; i <= n; ++i) {
            dp[i][i][1] = dp[i - 1][i - 1][1] + node[i].five;
            dp[i][i][2] = dp[i - 1][i - 1][2] + node[i].two;
            int temp = min(dp[i][i][1], dp[i][i][2]);
            dp[i][i][1] -= temp;
            dp[i][i][2] -= temp;
            dp[i][i][0] = dp[i - 1][i - 1][0] + temp;
            for(int j = 1; j <= min(i, k); ++j) {
                int temp = min(dp[i - 1][j - 1][1] + node[i].five, dp[i - 1][j - 1][2] + node[i].two);
                if(dp[i - 1][j - 1][0] + temp >= dp[i - 1][j][0]) {
                    dp[i][j][0] = dp[i - 1][j - 1][0] + temp;
                    dp[i][j][1] = dp[i - 1][j - 1][1] + node[i].five - temp;
                    dp[i][j][2] = dp[i - 1][j - 1][2] + node[i].two - temp;
                }
                else {
                    dp[i][j][0] = dp[i - 1][j][0];
                    dp[i][j][1] = dp[i - 1][j][1];
                    dp[i][j][2] = dp[i - 1][j][2];
                }
            }
        }
        printf("%d\n", dp[n][k][0]);
    }
    return 0;
}
