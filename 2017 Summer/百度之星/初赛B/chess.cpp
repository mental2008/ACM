#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1005;
int n, m;
LL dp[maxn][maxn];
bool vis[maxn][maxn];

LL dfs(int i, int j) {
	if(vis[i][j]) return dp[i][j] % MOD;
	for(int y = j - 1; y >= 1; y--) {
		if(min(i - 1, y) + 1 != min(i, j)) break;
		dp[i][j] = (dp[i][j] + dfs(i - 1, y)) % MOD;
	}
	vis[i][j] = 1;
	return dp[i][j] % MOD;
}

int main() {
	mem(dp, 0);
	mem(vis, 0);
	for(int i = 1; i < maxn; i++) {
		dp[i][1] = i % MOD;
		vis[i][1] = 1;
	}
	for(int i = 1; i < maxn; i++) {
		dp[1][i] = i % MOD;
		vis[1][i] = 1;
	}
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d", &n, &m);
		LL ans = dfs(n, m) % MOD;
		printf("%I64d\n", (ans % MOD));
	}
	return 0;
} 
