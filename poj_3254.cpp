#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 100000000
#define maxn 12 + 5
using namespace std;
int m, n;
int fertile[maxn];
int dp[maxn][600];
int state[600];
int top;

bool judge(int x, int y) {
	if(x & y) return false;
	return true;
}

bool ok(int x) {
	if(x & (x << 1)) return false;
	return true;
}

void init() {
	top = 0;
	int total = 1 << n;
	for(int i = 0; i < total; i++) {
		if(ok(i)) {
			state[top++] = i;
		}
	}
}

int main() {
	while(~scanf("%d%d", &m, &n)) {
		init();
		memset(fertile, 0, sizeof(fertile));
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				int num;
				scanf("%d", &num);
				fertile[i] <<= 1;
				if(num == 0)
					fertile[i] += 1;
			}
		}
		for(int i = 0; i < top; i++) {
			if(judge(fertile[1], state[i])) {
				dp[1][i] = 1;
			}
		}
		for(int i = 2; i <= m; i++) {
			for(int j = 0; j < top; j++) {
				if(judge(fertile[i], state[j])) {
					for(int k = 0; k < top; k++) {
						if(!judge(state[k], fertile[i - 1])) continue;
						if(judge(state[j], state[k])) {
							dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < top; i++) {
			ans = (ans + dp[m][i]) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
