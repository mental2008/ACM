#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 2005;
double dp[maxn];//滾動數組
int n, m, k;
double p1, p2, p3, p4;
double p[maxn];
double coe[maxn];
double exps = 1e-5;

int main() {
	while(~scanf("%d%d%d", &n, &m, &k)) {
		mem(dp, 0);
		scanf("%lf%lf%lf%lf", &p1, &p2, &p3, &p4);
		if(p4 < exps) {
			puts("0.00000");
			continue;
		}//要特判
		dp[1] = p4 / (1 - p1 - p2);
		double p21 = p2 / (1 - p1);
		double p31 = p3 / (1 - p1);
		double p41 = p4 / (1 - p1);
		p[0] = 1;
		for(int i = 1; i <= n; i++) p[i] = p[i - 1] * p21;
		for(int i = 2; i <= n; i++) {
			coe[1] = p41;
			for(int j = 2; j <= i; j++) {
				coe[j] = p31 * dp[j - 1] + p41 * (j <= k ? 1 : 0);
			}
			double temp = 0;
			for(int j = 1; j <= i; j++) {
				temp += coe[j] * p[i - j];
			}
			dp[i] = temp / (1 - p[i]);
			dp[1] = p21 * dp[i] + coe[1];
			for(int j = 2; j < i; j++) {
				dp[j] = p21 * dp[j - 1] + coe[j];
			}
		}
		printf("%.5lf\n", dp[m]);
	}
	return 0;
}
