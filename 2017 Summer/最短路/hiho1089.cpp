#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a, i) memset(a, i, sizeof(a))
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int d[maxn][maxn];
int n, m;

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) d[i][j] = 0;
				else d[i][j] = INF;
			}
		}
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			d[u][v] = min(d[u][v], w);
			d[v][u] = min(d[v][u], w);
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				printf("%d", d[i][j]);
				if(j != n) printf(" ");
			}
			puts("");
		}
	}
	return 0;
}
