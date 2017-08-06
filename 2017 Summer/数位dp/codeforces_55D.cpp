#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 2520;
LL l, r;
int Hash[mod + 10];
int num[20];
LL dp[20][mod + 5][100];

LL gcd(LL a, LL b) {
	return (b == 0 ? a : gcd(b, a % b));
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

LL dfs(int pos, int sum, int Lcm, bool flag) {
	if(pos == -1) return sum % Lcm == 0;
	if(!flag && dp[pos][sum][Hash[Lcm]] != -1) return dp[pos][sum][Hash[Lcm]];
	LL res = 0;
	int p = 0;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		res += dfs(pos - 1, (sum * 10 + i) % mod, i ? lcm(Lcm, i) : Lcm, flag && i == p);
	}
	if(!flag) dp[pos][sum][Hash[Lcm]] = res;
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
	int cnt = 0;
	for(int i = 1; i <= mod; i++) {
		if(mod % i == 0) Hash[i] = ++cnt;
	}
	memset(dp, -1, sizeof(dp));
	while(caseCnt--) {
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", cal(r) - cal(l - 1));
	}
	return 0;
}
