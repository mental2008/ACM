#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const int maxn = 250010;
int a[maxn];
int b[maxn];
int start[maxn];
int online[maxn];
int n;
int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		sort(b + 1, b + 1 + n);
		start[n] = a[n] - n;
		for(int i = n - 1; i >= 1; i--) {
			start[i] = max(a[i] - i, start[i + 1]);
		}
		LL ans = 0;
		ans = (ans + start[b[1]]) % MOD;
		online[1] = start[b[1]] - (n + 1);
		for(int i = 2; i <= n; i++) {
			LL temp = max(start[b[i]], online[i - 1]);
			online[i] = (temp - (n + i), online[i - 1]);
			ans = (ans + temp) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
