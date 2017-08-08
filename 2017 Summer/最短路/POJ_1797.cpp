#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
int n, m;
int a[maxn][maxn];
int d[maxn];
bool vis[maxn];

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; times++) {
		scanf("%d%d", &n, &m);
		mem(a, 0);
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			a[u][v] = a[v][u] = w;
		}
		mem(d, 0);
		mem(vis, 0);
		d[1] = INF;
		for(int i = 1; i <= n; i++) {
			int x;
			int temp = 0;
			for(int j = 1; j <= n; j++) {
				if(!vis[j] && d[j] >= temp) {
					temp = d[x = j];
				}
			}
			vis[x] = 1;
			for(int j = 1; j <= n; j++) {
				if(d[j] < d[x] && d[j] < a[x][j]) {
					d[j] = min(d[x], a[x][j]);
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n", times, d[n]);
	}
	return 0;
}
