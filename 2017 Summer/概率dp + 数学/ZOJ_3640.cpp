#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10005;
int n, f;
int c[maxn];
int t[maxn];
double dp[2 * maxn];
int main() {
	while(~scanf("%d%d", &n, &f)) {
		int MaxDiff = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
			MaxDiff = max(MaxDiff, c[i]);
			t[i] = (int)((1.0 + sqrt(5)) / 2 * c[i] * c[i]);
		}
		for(int i = MaxDiff * 2; i >= f; i--) {
			double p = 1.0 / n;
			dp[i] = 0;
			for(int j = 1; j <= n; j++) {
				if(i > c[j]) dp[i] += p * t[j];
				else dp[i] += p * (1 + dp[i + c[j]]);
			}
		}
		printf("%.3lf\n", dp[f]);
	}
	return 0;
}
