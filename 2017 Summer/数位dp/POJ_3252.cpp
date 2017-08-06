#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l, r;
int num[32];
LL dp[32][2][32][32];

LL dfs(int pos, bool isOne, int One, int Zero, bool flag) {
	if(pos == -1) {
		if(Zero >= One) return 1;
		else return 0;
	}
	if(!flag && dp[pos][isOne][One][Zero] != -1) return dp[pos][isOne][One][Zero];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 1;
	for(int i = 0; i <= p; i++) {
		if(isOne) {
			if(i == 1) res += dfs(pos - 1, isOne, One + 1, Zero, flag && i == p);
			else res += dfs(pos - 1, isOne, One, Zero + 1, flag && i == p);
		}
		else {
			if(i == 1) res += dfs(pos - 1, 1, One + 1, Zero, flag && i == p);
			else res += dfs(pos - 1, 0, One, Zero, flag && i == p);
		}
	}
	if(!flag) dp[pos][isOne][One][Zero] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x & 1;
		x >>= 1;
	}
	return dfs(i - 1, 0, 0, 0, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	while(~scanf("%lld%lld", &l, &r)) {
		printf("%lld\n", cal(r) - cal(l - 1));
	}
	return 0;
} 
