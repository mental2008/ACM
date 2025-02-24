// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
double p[10][200];
double dp[200][1 << 7];
bool vis[200][1 << 7];
int n, m;

double dfs(int res, int status) {
	if (res <= 0) return 0;
	if (vis[res][status]) return dp[res][status];
	vis[res][status] = 1;
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (status & (1 << (i - 1))) continue;
		double temp = 0;
		for (int j = 1; j <= res; ++j) {
			temp += p[i][j] * (1 + dfs(res - j, status | (1 << (i - 1))));
		}
		ans = max(ans, temp);
	}
	dp[res][status] = ans;
	return ans;
}

int main()
{
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> p[i][j];
			}
		}
		memset(vis, 0, sizeof(vis));
		double ans = dfs(m, 0);
		cout << fixed << setprecision(5) << ans << '\n';
	}
    return 0;
}

