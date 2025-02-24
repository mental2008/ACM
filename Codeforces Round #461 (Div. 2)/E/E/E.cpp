// E.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
LL dp[1005][10005];
LL n, W, B, X;
LL cost[1005];
LL c[1005];
LL sum[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> W >> B >> X;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	mem(dp, -1);
	dp[0][0] = W;
	mem(sum, 0);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + c[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= sum[i]; ++j) {
			for (int k = 0; k <= c[i]; ++k) {
				if (j < k) break;
				if (dp[i - 1][j - k] < 0) continue;
				dp[i][j] = max(dp[i][j], min(dp[i - 1][j - k] + X, W + (j - k) * B) - cost[i] * k);
			}
		}
	}
	for (int i = sum[n]; i >= 0; --i) {
		if (dp[n][i] >= 0) {
			cout << i << '\n';
			break;
		}
	}
    return 0;
}

