#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
int main() {
	double money;
	while(~scanf("%lf", &money)) {
		int n;
		scanf("%d", &n);
		double own = 0x3f3f3f3f;
		double ans = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++) {
			double price;
			scanf("%lf", &price);
			ans = max(ans, (money / own) * (price - own));
			own = min(own ,price);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
