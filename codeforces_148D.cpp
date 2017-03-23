#include <bits/stdc++.h>
#define maxn 1000 + 10
using namespace std;
double dp[maxn][maxn];
int main() {
	int w, b;
	memset(dp, 0, sizeof(dp));
	scanf("%d%d", &w, &b);
	for(int i = 1; i <= w; i++) dp[i][0] = 1.0;
	for(int i = 1; i <= b; i++) dp[0][i] = 0.0;
	for(int i = 1; i <= w; i++) {
		for(int j = 1; j <= b; j++) {
			dp[i][j] = 1.0 * i / (i + j);
			if(j >= 2) {
				dp[i][j] += (1.0 * j / (i + j)) * (1.0 * (j - 1) / (i + j - 1)) * (1.0 * i / (i + j - 2)) * dp[i - 1][j - 2];
			}
			if(j >= 3){
				dp[i][j] += (1.0 * j / (i + j)) * (1.0 * (j - 1) / (i + j - 1)) * (1.0 * (j - 2) / (i + j - 2)) * dp[i][j - 3];
			}
		}
	}
	printf("%.9lf\n", dp[w][b]);
	return 0;
}
