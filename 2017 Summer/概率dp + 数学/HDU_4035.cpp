#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 10005;
const double exps = 1e-10;
int n;
vector<int> G[maxn];
double k[maxn], e[maxn];
double A[maxn], B[maxn], C[maxn];

bool dfs(int u, int fa) {
	int len = G[u].size();
	A[u] = k[u];
	B[u] = (1 - k[u] - e[u]) / len;
	C[u] = 1 - k[u] - e[u];
	double temp = 0;
	for(int i = 0; i < len; i++) {
		int v = G[u][i];
		if(v == fa) continue;
		if(!dfs(v, u)) return false;
		A[u] += (1 - k[u] - e[u]) / len * A[v];
		C[u] += (1 - k[u] - e[u]) / len * C[v];
		temp += (1 - k[u] - e[u]) / len * B[v];
	}
	if(fabs(1 - temp) < exps) return false;
	A[u] /= (1 - temp);
	B[u] /= (1 - temp);
	C[u] /= (1 - temp);
	return true;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	int times = 0;
	while(caseCnt--) {
		scanf("%d", &n);
		for(int i = 0; i <= n; i++) G[i].clear();
		for(int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 1; i <= n; i++) {
			int ki, ei;
			scanf("%d%d", &ki, &ei);
			k[i] = ki / 100.0;
			e[i] = ei / 100.0;
		}
		if(dfs(1, -1) && fabs(1 - A[1]) > exps) {
			printf("Case %d: %.6lf\n", ++times, C[1] / (1 - A[1]));
		}
		else {
			printf("Case %d: impossible\n", ++times);
		}
	}
	return 0;
}
