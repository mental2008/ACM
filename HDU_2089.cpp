#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10][3]; // dp[i][j] i代表位数,j代表状况
//dp[i][0] 表示不存在不吉利数字
//dp[i][1] 表示不存在不吉利数字,且最高位为2
//dp[i][2] 表示存在不吉利数字

void init() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= 6; i++) {
		dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][0] + dp[i - 1][1]; 
	}
}

int solve(int n) {
	int a[10], len = 0, flag, sum = n, ans = 0;
	while(n) {
		a[++len] = n % 10;
		n /= 10;
	}
	a[len + 1] = 0;
	flag = 0;
	for(int i = len; i >= 1; i--) {
		ans += dp[i - 1][2] * a[i];
		if(flag)
			ans += dp[i - 1][0] * a[i];
		if(!flag && a[i] > 4)
			ans += dp[i - 1][0];
		if(!flag && a[i + 1] == 6 && a[i] > 2)
			ans += dp[i][1];
		if(!flag && a[i] > 6)
			ans += dp[i - 1][1];
		if(a[i] == 4 || (a[i + 1] == 6 && a[i] == 2))
			flag = 1;
	}
	return sum - ans;
}

int main() {
	int l, r;
	init();
	while(~scanf("%d%d", &l, &r)) {
		if(l == 0 && r == 0) break;
		printf("%d\n", solve(r + 1) - solve(l));
	}
	return 0;
}
