// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 105;
const double exps = 1e-10;
int n, m;
vector<int> G[maxn];
vector<int> weight[maxn];
int sum[maxn];
vector<int> F[maxn];
vector<double> pro[maxn];
bool vis[maxn];
double a[maxn][maxn];

void AddEdge(int u, int v, int val) {
	G[u].push_back(v);
	weight[u].push_back(val);
	sum[u] += val;
}

void dfs(int u) {
	vis[u] = 1;
	int len = G[u].size();
	for (int i = 0; i < len; ++i) {
		int v = G[u][i];
		F[v].push_back(u);
		pro[v].push_back((double)weight[u][i] / sum[u]);
		if (vis[v]) continue;
		dfs(v);
	}
}

bool l[maxn];
double ans[maxn];

int solve() {
	int res = 0, r = 0;
	for (int i = 0; i < n; ++i) l[i] = false;
	for (int i = 0; i < n; ++i) {
		for (int j = r; j < n; ++j) {
			if (fabs(a[i][j]) > exps) {
				for (int k = i; k <= n; ++k) {
					swap(a[j][k], a[r][k]);
				}
				break;
			}
		}
		if (fabs(a[r][i]) < exps) {
			++res;
			continue;
		}
		for (int j = 0; j < n; ++j) {
			if (j != r && fabs(a[j][i]) > exps) {
				double temp = a[j][i] / a[r][i];
				for (int k = i; k <= n; ++k) {
					a[j][k] -= temp * a[r][k];
				}
			}
		}
		l[i] = true;
		++r;
	}
	for (int i = 0; i < n; ++i) {
		if (l[i]) {
			for (int j = 0; j < n; ++j) {
				if (fabs(a[j][i]) > 0) {
					ans[i] = a[j][n] / a[j][i];
				}
			}
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(sum, 0, sizeof(sum));
	for (int i = 0; i < m; ++i) {
		int u, v, val;
		cin >> u >> v >> val;
		AddEdge(u, v, val);
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i) {
		int len = F[i].size();
		for (int j = 0; j < len; ++j) {
			int v = F[i][j];
			double prob = pro[i][j];
			a[i][v] += prob;
		}
		a[i][i] -= 1.0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

		}
	}
	return 0;
}

