#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int num[30];
int temp[30];
LL dp[30][40][40][2];

LL dfs(int pos, int start, int k, bool ok, bool flag) {
	if(pos == -1) {
		if(ok) return k;
		else return 1;
	}
	if(!flag && dp[pos][start][k][ok] != -1) return dp[pos][start][k][ok];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = k - 1;
	for(int i = 0; i <= p; i++) {
		temp[pos] = i;
		if(start == pos) {
			if(i == 0) res += dfs(pos - 1, start - 1, k, ok, flag && i == p);
			else res += dfs(pos - 1, start, k, ok, flag && i == p);
		}
		else if(pos >= (start + 1) / 2) {
			res += dfs(pos - 1, start, k, ok, flag && i == p);
		}
		else res += dfs(pos - 1, start, k, ok && i == temp[start - pos], flag && i == p);
	}
	if(!flag) dp[pos][start][k][ok] = res;
	return res;
}

LL cal(LL x, int k) {
	int i = 0;
	while(x) {
		num[i++] = x % k;
		x /= k;
	}
	return dfs(i - 1, i - 1, k, 1, 1);
}

int main() {
	mem(dp, -1);
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; ++times) {
		mem(temp, 0);
		LL L, R;
		int l, r;
		scanf("%lld%lld%d%d", &L, &R, &l, &r);
		LL ans = 0;
		for(int i = l; i <= r; i++) {
			ans += cal(R, i) - cal(L - 1, i);
		}
		printf("Case #%d: %lld\n", times, ans);
	}
	return 0;
} 
