#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define mem(a, i) memset(a, i, sizeof(a))
const double INF = 1e18;
const int maxn = 205;
int n;
double x[maxn];
double y[maxn];
double a[maxn][maxn];
double d[maxn];
bool vis[maxn];

double cal(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
	int times = 0;
	while(~scanf("%d", &n), n) {
		times++;
		for(int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		d[1] = 0;
		for(int i = 2; i <= n; i++) d[i] = INF;
		mem(vis, 0);
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				double dis = cal(i, j);
				a[i][j] = a[j][i] = dis;
			}
		}
		printf("Scenario #%d\n", times);
		for(int i = 1; i <= n; i++) {
			int x;
			double temp = INF;
			for(int j = 1; j <= n; j++) {
				if(!vis[j] && d[j] <= temp) {
					temp = d[x = j];
				}
			}
			vis[x] = 1;
			for(int j = 1; j <= n; j++) {
				if(d[j] > d[x] && d[j] > a[x][j]) d[j] = max(d[x],  a[x][j]);
			}
		}
		printf("Frog Distance = %.3lf\n\n", d[2]);
	}
	return 0;
}
