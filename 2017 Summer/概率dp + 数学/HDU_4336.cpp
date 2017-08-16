#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = (1 << 21);
int n;
double p[25];
double dp[maxn];

int main() {
	while(~scanf("%d", &n)) {
		double sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lf", &p[i]);
			sum += p[i];
		}
		mem(dp, 0);
		dp[(1 << n) - 1] = 0;
		for(int i = (1 << n) - 2; i >= 0; i--) {
			double p1 = 0;
			double temp = 1;
			for(int j = 0; j < n; j++) {
				if(!(i & (1 << j))) {
					temp += p[j] * dp[i | (1 << j)];
				}
				else p1 += p[j];
			}
			dp[i] = temp / (sum - p1);
		}
		printf("%.4lf\n", dp[0]);
	}
	return 0;
}
