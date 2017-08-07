#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL l, r;
int k;
int num[20];
LL dp[20][20][20][2];
LL pre[20];

LL dfs(int pos, int divide, int mod, bool zero, bool flag) {
	if(pos == -1) return mod == 0 ? 1 : 0;
	if(!flag && dp[pos][divide][mod][zero] != -1) return dp[pos][divide][mod][zero];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(zero && i == 0 && pos == divide + 1) continue;
		if(pos > divide) {
			res += dfs(pos - 1, divide, (i * pre[pos - divide - 1] + mod) % k, zero && i == 0, flag && i == p);
		}
		else {
			res += dfs(pos - 1, divide, (i * pre[pos] + mod) % k, zero && i == 0, flag && i == p);
		}
	}
	if(!flag) dp[pos][divide][mod][zero] = res;
	return res;
}

LL cal(LL x) {
	int i = 0;
	while(x) {
		num[i++] = x % 10;
		x /= 10;
	}
	LL ans = 0;
	for(int j = 0; j < i - 1; j++) {
		ans += dfs(i - 1, j, 0, 1, 1);
	}
	return ans;
}

int main() {
	pre[0] = 1;
	for(int i = 1; i < 20; i++) {
		pre[i] = pre[i - 1] * 10;
	}
	while(~scanf("%lld%lld%d", &l, &r, &k)) {
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", cal(r) - cal(l - 1));
	}
	return 0;
}
