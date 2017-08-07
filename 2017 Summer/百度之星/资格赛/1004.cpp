#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxb = 1005;
int B;
int N;
int score[maxn];
int cost[maxn];
int dp[maxb];
bool path[maxb][maxb];
int a[maxb][maxn];

int check(int i, int j) {
	int lenp = a[i][0];
	int lenq = a[j][0];
	for(int p = 1, q = 1; p <= lenp && q <= lenq; p++, q++) {
		if(a[i][p] != a[j][q]) return a[i][p] - a[j][q];
	}
	return 0;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; times++) {
		scanf("%d", &B);
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &score[i], &cost[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		for(int i = 1; i <= N; i++) {
			for(int j = B; j >= cost[i]; j--) {
				if(dp[j] < dp[j - cost[i]] + score[i]) {
					dp[j] = max(dp[j], dp[j - cost[i]] + score[i]);
					path[i][j] = 1;
				}
			}
		}
		LL maxscore = 0;
		for(int i = 0; i <= B; i++) {
			maxscore = max(maxscore, (LL)dp[i]);
		}
		LL minsum = 1e18;
		int k = 0, mark = 0;
		for(int i = B; i >= 0; i--) {
			if((LL)dp[i] == maxscore) {
				LL sum = 0;
				int p = N, q = i;
				int now = 1;
				while(p >= 1 && q >= 0) {
					if(path[p][q]) {
						a[k][now++] = p;
						sum += p;
						q -= cost[p];
					}
					p--;
				}
				a[k][0] = now - 1; //个数
				//printf("%d\n", a[k][0]);
				sort(a[k] + 1, a[k] + 1 + a[k][0]);
				if(minsum > sum) {
					minsum = sum;
					mark = k;
				}
				else if(minsum == sum && check(k, mark) < 0) {
					mark = k;
				}
				k++;
			}
		}
		LL anscost = 0;
		//sort(a[mark] + 1, a[mark] + 1 + a[mark][0]);
		for(int i = 1; i <= a[mark][0]; i++) anscost += cost[a[mark][i]];
		printf("Case #%d:\n", times);
		printf("%lld %lld\n", maxscore, anscost);
		for(int i = 1; i <= a[mark][0]; i++) {
			printf("%d", a[mark][i]);
			if(i == a[mark][0]) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
