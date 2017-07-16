#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 10;
int n;
LL a[maxn];
int main() {
	while(~scanf("%d", &n)) {
		LL sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		LL ans = 1e+18;
		LL temp = 0;
		for(int i = 1; i < n; i++) {
			temp += a[i];
			ans = min(ans, abs(sum - 1LL * 2 * temp));
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
