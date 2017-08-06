#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n;
LL dp[20][2][2];
int num[20];

LL dfs(int pos, bool iffour, bool if49, bool flag) {
	if(pos == -1) return if49;
	if(!flag && dp[pos][iffour][if49] != -1) return dp[pos][iffour][if49];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(iffour) {
			if(i == 9) res += dfs(pos - 1, 0, 1, flag && i == p);
			else if(i == 4) res += dfs(pos - 1, 1, if49, flag && i == p);
			else res += dfs(pos - 1, 0, if49, flag && i == p);
		}
		else {
			if(i == 4) res += dfs(pos - 1, 1, if49, flag && i == p);
			else res += dfs(pos - 1, 0, if49, flag && i == p);
		}
	}
	if(!flag) dp[pos][iffour][if49] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	return dfs(i - 1, 0, 0, 1);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%lld", &n);
		printf("%lld\n", cal(n));
	}
	return 0;
}
