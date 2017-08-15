#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
const double exps = 1e-9;
int n, m;
double A[maxn][maxn], B[maxn][maxn], C[maxn][maxn];
double dp[maxn][maxn];
int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%lf%lf%lf", &A[i][j], &B[i][j], &C[i][j]);
			}
		}
		mem(dp, 0);
		for(int i = n; i >= 1; i--) {
			for(int j = m; j >= 1; j--) {
				if(i == n && j == m) continue;
				if(fabs(1 - A[i][j]) < exps) {
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = (2 + B[i][j] * dp[i][j + 1] + C[i][j] * dp[i + 1][j]) / (1 - A[i][j]);
			}
		}
		printf("%.3lf\n", dp[1][1]);
	}
	return 0;
}
