//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
const int maxn = 1005;
const int INF = (1 << 30) - 1;
int n, m;
int pre[maxn], low[maxn];
int in[maxn];
vector<int> vec[maxn];
int dfs_clock;

void init() {
	for(int i = 0; i < maxn; i++) vec[i].clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	memset(in, 0, sizeof(in));
	dfs_clock = 0;
}

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	for(int i = 0; i < vec[u].size(); i++) {
		int v = vec[u][i];
		if(!pre[v]) {
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
		}
		else if(pre[v] < pre[u] && v != fa) {
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		dfs(1, 1);
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < vec[i].size(); j++) {
				int v = vec[i][j];
				if(low[v] != low[i]) {
					in[low[i]]++;
				}
			}
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(in[i] == 1) ans++;
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}
