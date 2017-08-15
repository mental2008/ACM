#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1005;
int n, m;
LL C[maxn][maxn];

int main() {
	C[0][0] = 1;
	for(int i = 1; i < maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d", &n, &m);
		if(n <= m) {
			printf("%I64d\n", C[m][n]);
		}
		else {
			printf("%I64d\n", C[n][m]);
		}
	}
	return 0;
} 
