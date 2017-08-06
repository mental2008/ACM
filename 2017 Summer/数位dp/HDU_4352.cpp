#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l, r;
int k;
int num[20];
LL dp[20][1 << 10][15];

int len(int sum) {
	int count = 0;
	while(sum) {
		if(sum & 1) count++;
		sum >>= 1;
	}
	return count;
}

int getSum(int sum, int i) {
	for(int j = i; j <= 9; j++) {
		if(sum & (1 << j)) return ((sum ^ (1 << j)) | (1 << i));
	}
	return sum | (1 << i);
}

LL dfs(int pos, int sum, bool zero, bool flag) {
	if(pos == -1) return len(sum) == k;
	if(!flag && dp[pos][sum][k] != -1) return dp[pos][sum][k];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		res += dfs(pos - 1, (zero && i == 0 ? 0 : getSum(sum, i)), zero && i == 0, flag && i == p);
	}
	if(!flag) dp[pos][sum][k] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	return dfs(i - 1, 0, 1, 1);
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	memset(dp, -1, sizeof(dp));
	for(int times = 1; times <= caseCnt; times++) {
		scanf("%lld%lld%d", &l, &r, &k);
		printf("Case #%d: %lld\n", times, cal(r) - cal(l - 1));
	}
	return 0;
}
