#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l, r;
LL dp[20][12][12][20];
int k;
int num[20];

LL dfs(int pos, int now, int increase, bool flag, int sum) {
	if(pos == -1) {
		if(sum == k) return 1;
		else return 0;
	}
	if(!flag && dp[pos][now][increase][sum] != -1) return dp[pos][now][increase][sum];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(now < i) res += dfs(pos - 1, i, increase + 1, flag && i == p, max(sum, increase + 1));
		else res += dfs(pos - 1, i, 0, flag && i == p, sum);
	}
	if(!flag) dp[pos][now][increase][sum] = res;
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
	int caseCnt;
	scanf("%d", &caseCnt);
	memset(dp, -1, sizeof(dp));
	while(caseCnt--) {
		scanf("%lld%lld%d", &l, &r, &k);
		printf("%lld\n", cal(r) - cal(l - 1));
	}
	return 0;
} 
