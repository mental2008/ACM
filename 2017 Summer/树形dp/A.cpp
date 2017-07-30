#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n;
LL dp[maxn][2];
int color[maxn];
vector<int> G[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	memset(color, 0, sizeof(color));
	memset(dp, 0, sizeof(dp));
}

void dfs(int u) {
	dp[u][color[u]] = 1;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
		dp[u][1] = (dp[u][1] * dp[v][0] + dp[u][1] * dp[v][1] + dp[u][0] * dp[v][1]) % MOD;
		dp[u][0] = (dp[u][0] * dp[v][0] + dp[u][0] * dp[v][1]) % MOD;
	}
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 0; i < n - 1; i++) {
			int v;
			scanf("%d", &v);
			G[v].push_back(i + 1);
		}
		for(int i = 0; i < n; i++) scanf("%d", &color[i]);
		dfs(0);
		printf("%lld\n", dp[0][1]);
	}
	return 0;
}
