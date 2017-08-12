#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 25;
int n, r;
double P[maxn];

double dfs(int now, int cnt, double res) {
	if(now == n) {
		if(cnt == r) return res;
		else return 0;
	}
	return dfs(now + 1, cnt + 1, res * P[now + 1]) + dfs(now + 1, cnt, res * (1 - P[now + 1]));
}

double dfs1(int now, int cnt, double res, int num) {
	if(now == n) {
		if(cnt == r) return res;
		else return 0;
	}
	if(now + 1 == num) return dfs1(now + 1, cnt + 1, res, num);
	else return dfs1(now + 1, cnt + 1, res * P[now + 1], num) + dfs1(now + 1, cnt, res * (1 - P[now + 1]), num);
}

int main() {
	int times = 0;
	while(~scanf("%d%d", &n, &r), n || r) {
		for(int i = 1; i <= n; i++) {
			scanf("%lf", &P[i]);
		}
		double E = dfs(0, 0, 1);
		printf("Case %d:\n", ++times);
		for(int i = 1; i <= n; i++) {
			double Ei = P[i] * dfs1(0, 0, 1, i);
			printf("%.6lf\n", Ei / E);
		}
	}
	return 0;
}
