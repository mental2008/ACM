#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
int t, n;
int a[maxn][maxn];
int d[maxn];
bool vis[maxn];
int main() {
	while(~scanf("%d%d", &t, &n)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) a[i][j] = 0;
				else a[i][j] = INF;
			}
		}
		d[1] = 0;
		for(int i = 2; i <= n; i++) d[i] = INF;
		mem(vis, 0);
		for(int i = 0; i < t; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			a[u][v] = min(a[u][v], w);
			a[v][u] = min(a[v][u], w);
		}
		//vis[1] = 1;
		for(int i = 1; i <= n; i++) {
			int x;
			int temp = INF;
			for(int j = 1; j <= n; j++) {
				if(!vis[j] && d[j] <= temp) {
					temp = d[x = j];
				}
			}
			vis[x] = 1;
			for(int j = 1; j <= n; j++) {
				d[j] = min(d[j], d[x] + a[x][j]);
			}
		}
		printf("%d\n", d[n]);
	}
	return 0;
}
