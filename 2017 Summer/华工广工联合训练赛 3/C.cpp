#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL N;
int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%lld", &N);
		LL maxn = (sqrt(1 + 8 * N) - 1) / 2;
		LL a = -1, num = 0;
		for(LL i = 2; i <= maxn; i++) {
			LL temp = N * 2 - i * i + i;
			if(temp % (2 * i) == 0) {
				a = temp / (2 * i);
				num = i;
				break;
			}
		}
		if(num == 0) puts("IMPOSSIBLE");
		else {
			printf("%lld = %lld", N, a);
			for(LL i = a + 1; i <= a + num - 1; i++) {
				printf(" + %lld", i);
			}
			puts("");
		}
	}
	return 0;
} 
