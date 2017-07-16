#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int energy[maxn], potion[maxn];
int dp[300][110][110][2];
int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		int k, m;
		scanf("%d%d", &k, &m);
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &energy[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &potion[i]);
		memset(dp, -1, sizeof(dp));
		dp[0][100][0][0] = 0;
		int ans = 0;
		for(int i = 0; i < (1 << n); i++) {
			for(int j = 100; j >= 1; j--) {
				for(int l = 99; l >= 0; l--) {
					for(int p = 0; p <= 1; p++) {
						if(dp[i][j][l][p] >= 0) {
							ans = max(ans, dp[i][j][l][p]);
							if(j > k) dp[i][j - k][max(0, l - m)][0] = max(dp[i][j - k][max(0, l - m)][0], dp[i][j][l][p] + 1);
							if(p == 0) {
								for(int x = 0; x < n; x++) {
									if(!((i >> x) & 1)) {
										if(potion[x + 1] + l < 100) {
											dp[i | (1 << x)][min(100, j + energy[x + 1])][potion[x + 1] + l][1] = max(dp[i | (1 << x)][min(100, j + energy[x + 1])][potion[x + 1] + l][1], dp[i][j][l][p]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
