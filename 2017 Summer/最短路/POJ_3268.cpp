#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
int n, m;
int party;
int a[maxn][maxn];
int d1[maxn];
int d2[maxn];
bool vis1[maxn];
bool vis2[maxn];

int main() {
	while(~scanf("%d%d%d", &n, &m, &party)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) a[i][j] = 0;
				else a[i][j] = INF;
			}
		}
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			a[u][v] = min(a[u][v], w);
		}
		mem(vis1, 0);
		d1[party] = d2[party] = 0;
		for(int i = 1; i <= n; i++) {
			if(i == party) continue;
			d1[i] = d2[i] = INF;
		}
		for(int i = 1; i <= n; i++) {
			int x;
			int temp = INF;
			for(int j = 1; j <= n; j++) {
				if(!vis1[j] && d1[j] <= temp) {
					temp = d1[x = j];
				}
			}
			vis1[x] = 1;
			for(int j = 1; j <= n; j++) {
				d1[j] = min(d1[j], d1[x] + a[x][j]);
			}
		}
		mem(vis2, 0);
		for(int i = 1; i <= n; i++) {
			int x;
			int temp = INF;
			for(int j = 1; j <= n; j++) {
				if(!vis2[j] && d2[j] <= temp) {
					temp = d2[x = j];
				}
			}
			vis2[x] = 1;
			for(int j = 1; j <= n; j++) {
				d2[j] = min(d2[j], d2[x] + a[j][x]);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			//if(i == party) continue;
			ans = max(ans, d2[i] + d1[i]);
			//printf("%d %d\n", d1[i], d2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
