#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL dp[30][30];
int num[30];

LL dfs(int n, int pos, bool flag) {
	if(pos == -1) return n;
	if(!flag && dp[pos][n] != -1) return dp[pos][n];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(i == 1) {
			res += dfs(n + 1, pos - 1, flag && i == p);
		}
		else {
			res += dfs(n, pos - 1, flag && i == p);
		}
	}
	if(!flag) dp[pos][n] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	return dfs(0, i - 1, 1);
}

int main() {
	LL a, b;
	memset(dp, -1, sizeof(dp));
	while(~scanf("%I64d%I64d", &a, &b)) {
		if(a > b) swap(a, b);
		printf("%I64d\n", cal(b) - cal(a - 1));
	}
	return 0;
}
