#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 100005;
double dp[maxn];
int n, m;
int line[maxn];
int main() {
	while(~scanf("%d%d", &n, &m), n || m) {
		mem(line, 0);
		for(int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			line[x] = y;
		}
		mem(dp, 0);
		for(int i = n - 1; i >= 0; i--) {
			if(line[i]) {
				dp[i] = dp[line[i]];
			}
			else {
				dp[i] = 1;
				for(int j = 1; j <= 6; j++) {
					dp[i] += (1.0 / 6 * dp[i + j]);
				}
			}
		}
		printf("%.4lf\n", dp[0]);
	}
	return 0;
}
