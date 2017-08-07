#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100005;
const int maxm = 1005;
int n, m;
int a[maxn];
int b[maxn];
int k[maxm];
int p[maxm];
LL dp[12][maxn];

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int health = 0, defence = 0, damage = 0;
		for(int i = 0; i <= 10; i++) dp[i][0] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			health = max(health, a[i]);
			defence = max(defence, b[i]);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &k[i], &p[i]);
			damage = max(damage, p[i]);
		}
		if(damage <= defence) {
			puts("-1");
		}
		else {
			for(int i = 0; i <= defence; i++) {
				for(int j = 1; j <= health; j++) {
					dp[i][j] = 1e18;
					for(int l = 1; l <= m; l++) {
						if(p[l] - i >= j) {
							dp[i][j] = min(dp[i][j], (LL)k[l]);
						}
						else if(p[l] <= i) continue;
						else {
							dp[i][j] = min(dp[i][j], dp[i][j - p[l] + i] + k[l]);
						}
					}
				}
			}
			LL ans = 0;
			for(int i = 1; i <= n; i++) {
				ans += dp[b[i]][a[i]];
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
