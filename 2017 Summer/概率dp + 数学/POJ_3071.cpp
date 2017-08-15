#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 130;
int n;
double dp[10][maxn];
double P[maxn][maxn];

int main() {
	while(~scanf("%d", &n), n != -1) {
		for(int i = 1; i <= (1 << n); i++) {
			for(int j = 1; j <= (1 << n); j++) {
				scanf("%lf", &P[i][j]);
			}
		}
		for(int i = 1; i <= (1 << n); i++) dp[0][i] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= (1 << n); j++) {
				dp[i][j] = dp[i - 1][j];
				double temp = 0;
				for(int k = 1; k <= (1 << n); k++) {
					if(j == k) continue;
					if(((j - 1) >> i) == ((k - 1) >> i)) {
						int a = ((j - 1) >> (i - 1)) & 1;
						int b = ((k - 1) >> (i - 1)) & 1;
						if(a ^ b) {
							temp += (dp[i - 1][k] * P[j][k]);
						}
					}
				}
				dp[i][j] *= temp;
			}
		}
		int ans = 1;
		double temp = dp[n][1];
		for(int i = 2; i <= (1 << n); i++) {
			if(temp < dp[n][i]) {
				ans = i;
				temp = dp[n][i];
			}
		}
		/*for(int i = 1; i <= (1 << n); i++) {
			printf("%d %lf\n", i, dp[n][i]);
		}*/
		printf("%d\n", ans);
	}
	return 0;
}//神奇的位运算
