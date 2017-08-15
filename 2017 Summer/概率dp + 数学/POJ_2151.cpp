#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxT = 1005;
const int maxM = 35;
int M, T, N;
double P[maxT][maxM];
double dp[maxT][maxM][maxM];

int main() {
	while(~scanf("%d%d%d", &M, &T, &N), M || T || N) {
		for(int i = 1; i <= T; i++) {
			for(int j = 1; j <= M; j++) {
				scanf("%lf", &P[i][j]);
			}
		}
		double p1 = 1;
		for(int i = 1; i <= T; i++) {
			double temp = 1;
			for(int j = 1; j <= M; j++) {
				temp *= (1 - P[i][j]);
			}
			p1 *= (1 - temp);
		}
		mem(dp, 0);
		for(int i = 1; i <= T; i++) {
			dp[i][0][0] = 1;
			for(int j = 1; j <= M; j++) {
				dp[i][j][0] = dp[i][j - 1][0] * (1 - P[i][j]);
				for(int k = 1; k < j; k++) {
					dp[i][j][k] = dp[i][j - 1][k - 1] * P[i][j] + dp[i][j - 1][k] * (1 - P[i][j]);
				}
				dp[i][j][j] = dp[i][j - 1][j - 1] * P[i][j];
			}
		}
		double p2 = 1;
		for(int i = 1; i <= T; i++) {
			double temp = 0;
			for(int j = 1; j <= N - 1; j++) {
				temp += dp[i][M][j];
			}
			p2 *= temp;
		}
		printf("%.3lf\n", p1 - p2);
	}
	return 0;
}//所有队伍至少一题 - 所有队伍至少1～（N - 1）题
