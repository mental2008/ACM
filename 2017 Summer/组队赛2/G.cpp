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
LL dp[10005][15][15];
bool vis[15][15];
int n, m, p;

void extendGcd(LL a, LL b, LL &x, LL &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		extendGcd(b, a % b, x, y);
		LL tmp = x;
		x = y;
		y = tmp - a / b * y;
		return;
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(~scanf("%d%d%d", &n, &m, &p)) {
        mem(vis, 0);
        for(int i = 0; i < p; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            vis[u][v] = vis[v][u] = 1;
        }
        if(m == 1) {
            puts("1");
            continue;
        }
        mem(dp, 0);
        for(int i = 1; i <= m; ++i) dp[1][i][i] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int k = 1; k <= m; ++k) {
                    if(vis[j][k]) continue;
                    for(int l = 1; l <= m; l++) {
                        dp[i][j][l] = (dp[i][j][l] + dp[i - 1][k][l]) % MOD;
                    }
                }
            }
        }
        LL x, y;
        extendGcd(1LL * n, MOD, x, y);
        while(y < 0) y += n;
        LL sum = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(vis[i][j]) continue;
                sum = (sum + dp[n][i][j]) % MOD;
            }
        }
        sum = (sum * y) % MOD;
        printf("%lld\n", (sum % MOD + MOD) % MOD / 2);
    }
    return 0;
}
