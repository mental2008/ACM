#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int d[maxn][maxn];
int n, m, hole;

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d%d", &n, &m, &hole);
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
		for(int i = 1; i <= hole; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			d[u][v] = min(d[u][v], -w);
		}
		bool ok = false;
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];//min function is so slow....
				}
				if(d[i][i] < 0) {
					ok = true;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
