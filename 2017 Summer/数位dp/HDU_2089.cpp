#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, m;
LL dp[20][2];
int num[20];

LL dfs(int pos, bool six, bool flag) {
	if(pos == -1) return 1;
	if(!flag && dp[pos][six] != -1) return dp[pos][six];
	LL res = 0, p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(i == 4 || (six && i == 2)) continue;
		if(i == 6) res += dfs(pos - 1, 1, flag && i == p);
		else res += dfs(pos - 1, 0, flag && i == p);
	}
	if(!flag) dp[pos][six] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i] = x % 10;
		i++;
		x /= 10;
	}
	return dfs(i - 1, 0, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	while(~scanf("%lld%lld", &n, &m), n || m) {
		printf("%lld\n", cal(m) - cal(n - 1));
	}
	return 0;
}
