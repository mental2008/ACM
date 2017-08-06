#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n;
int num[20];
LL dp[20][20][2][10];

LL dfs(int pos, int mod, bool have, bool flag, int pre) {
	if(pos == -1) {
		if(mod == 0 && have == 1) return 1;
		else return 0;
	}
	if(!flag && dp[pos][mod][have][pre] != -1) return dp[pos][mod][have][pre];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		int newmod = (mod * 10 + i) % 13;
		if(pre == 1 && i == 3) res += dfs(pos - 1, newmod, 1, flag && i == p, i);
		else {
			res += dfs(pos - 1, newmod, have, flag && i == p, i);
		}
	}
	if(!flag) dp[pos][mod][have][pre] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	return dfs(i - 1, 0, 0, 1, 0);
}

int main() {
	memset(dp, -1, sizeof(dp));
	while(~scanf("%lld", &n)) {
		printf("%lld\n", cal(n));
	}
	return 0;
}
