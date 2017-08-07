#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l, r;
int num[20];
LL dp[20][20][5005][2];

LL dfs(int pos, int fulcrum, int work, bool zero, bool flag) {
	if(pos == -1) {
		if(!zero) return work == 0;
		else return 0;
	}
	if(pos < fulcrum && work < 0) return 0;
	if(!flag && dp[pos][fulcrum][work + 2500][zero] != -1) return dp[pos][fulcrum][work + 2500][zero];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		res += dfs(pos - 1, fulcrum, work + (pos - fulcrum) * i, zero && i == 0, flag && i == p);
	}
	if(!flag) dp[pos][fulcrum][work + 2500][zero] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	LL ans = 0;
	for(int j = 0; j <= i - 1; j++) {
		ans += dfs(i - 1, j, 0, 1, 1);
	}
	return ans + 1;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	memset(dp, -1, sizeof(dp));
	while(caseCnt--) {
		scanf("%lld%lld", &l, &r);
		if(l == 0) {
			if(r == 0) puts("1");
			else printf("%lld\n", cal(r));
		}
		else printf("%lld\n", cal(r) - cal(l - 1));
	}
	return 0;
}
