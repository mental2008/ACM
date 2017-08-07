#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLR(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
LL l, r;
int x, y;
int num[20];
LL dp[20][20][20];

LL dfs(int pos, int four, int seven, bool flag) {
	if(pos == -1) return (four == x && seven == y);
	if(!flag && dp[pos][four][seven] != -1) return dp[pos][four][seven];
	LL res = 0;
	int p;
	if(flag) p = num[pos];
	else p = 9;
	for(int i = 0; i <= p; i++) {
		if(i == 4) res += dfs(pos - 1, four + 1, seven, flag && i == p);
		else if(i == 7) res += dfs(pos - 1, four, seven + 1, flag && i == p);
		else res += dfs(pos - 1, four, seven, flag && i == p);
	}
	if(!flag) dp[pos][four][seven] = res;
	return res;
}

LL cal(LL temp) {
	int i = 0;
	while(temp) {
		num[i++] = temp % 10;
		temp /= 10;
	}
	return dfs(i - 1, 0, 0, 1);
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; times++) {
		CLR(dp, -1);
		scanf("%lld%lld", &l, &r);
		scanf("%d%d", &x, &y);
		LL lower = cal(l), upper = cal(r);
//		printf("%lld %lld\n", lower, upper);
		printf("Case #%d:\n", times);
		int n, k;
		scanf("%d", &n);
		while(n--) {
			scanf("%d", &k);
			if(k > upper - lower) {
				puts("Nya!");
				continue;
			}
			LL lef = l + 1, rig = r;
			LL ans = -1;
			while(lef <= rig) {
				LL mid = (lef + rig) / 2;
				LL temp = cal(mid);
				if(temp - lower >= k) {
					ans = mid;
					rig = mid - 1;
				}
				else {
					lef = mid + 1;
				}
				
			}
			if(ans == -1) puts("Nya!");
			else printf("%lld\n", ans);
		}
	}
	return 0;
} 
