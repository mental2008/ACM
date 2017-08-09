#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n, m;
int d[maxn][maxn];
int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) d[i][j] = 1;
				else d[i][j] = 0;
			}
		}//init
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			d[u][v] = 1;
		}//input
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					d[i][j] = (d[i][j] || (d[i][k] && d[k][j]));
				}
			}
		}//floyd
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			int sum = 0;
			for(int j = 1; j <= n; j++) {
				if(d[i][j] || d[j][i]) sum++;
			}
			if(sum == n) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
