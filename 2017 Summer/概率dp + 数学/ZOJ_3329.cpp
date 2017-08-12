#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 505;
int n, k1, k2, k3, a, b, c;
double A[maxn];
double B[maxn];
int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
		mem(A, 0);
		mem(B, 0);
		for(int i = n; i >= 0; i--) {
			double p0 = (1.0 / k1) * (1.0 / k2) * (1.0 / k3);
			A[i] = p0;
			B[i] = 1;
			for(int j = 1; j <= k1; j++) {
				for(int p = 1; p <= k2; p++) {
					for(int q = 1; q <= k3; q++) {
						if(j == a && p == b && q == c) continue;
						A[i] += (p0 * A[i + j + p + q]);
						B[i] += (p0 * B[i + j + p + q]);
					}
				}
			}
		}
		double ans = B[0] / (1 - A[0]);
		printf("%.15lf\n", ans);
	}
	return 0;
}
