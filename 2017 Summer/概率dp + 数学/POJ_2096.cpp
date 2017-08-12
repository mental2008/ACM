#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
double dp[maxn][maxn];
int n, s;
int main() {
	while(~scanf("%d%d", &n, &s)) {
		mem(dp, 0);
		for(int i = n; i >= 0; i--) {
			for(int j = s; j >= 0; j--) {
				if(i == n && j == s) continue;
				double p1 = (double) i * j / (double)(n * s);
				double p2 = (double) (n - i) * j / (double)(n * s);
				double p3 = (double) i * (s - j) / (double)(n * s);
				double p4 = (double) (n - i) * (s - j) / (double)(n * s);
				dp[i][j] = (1 + p2 * dp[i + 1][j] + p3 * dp[i][j + 1] + p4 * dp[i + 1][j + 1]) / (1 - p1);
			}
		}
		printf("%.4f\n", dp[0][0]);
	}
	return 0;
}
