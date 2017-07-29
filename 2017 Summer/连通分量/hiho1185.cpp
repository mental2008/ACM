#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 20005;
int n, m;
int w[maxn];
vector<int> G[maxn];
int pre[maxn], lowlink[maxn];
int sccno[maxn];
int dfs_clock;
int scc_cnt;
stack<int> s;
int weight[maxn];
vector<int> vec[maxn];
int ans;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	memset(pre, 0, sizeof(pre));
	memset(lowlink, 0, sizeof(lowlink));
	memset(sccno, 0, sizeof(sccno));
	dfs_clock = scc_cnt = 0;
	while(!s.empty()) s.pop();
	memset(weight, 0, sizeof(weight));
	for(int i = 0; i < maxn; i++) vec[i].clear();
	ans = 0;
}

void dfs(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	s.push(u);
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!pre[v]) {
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(!sccno[v]) {
			lowlink[u] = min(lowlink[u], pre[v]);
		}
	}
	if(pre[u] == lowlink[u]) {
		scc_cnt++;
		while(1) {
			int x = s.top();
			s.pop();
			sccno[x] = scc_cnt;
			weight[scc_cnt] += w[x];
			if(x == u) break;
		}
	}
}

void newdfs(int u, int sum) {
	ans = max(sum, ans);
	for(int i = 0; i < vec[u].size(); i++) {
		int v = vec[u][i];
		newdfs(v, sum + weight[v]);
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < G[i].size(); j++) {
				int v = G[i][j];
				if(sccno[i] != sccno[v]) {
					vec[sccno[i]].push_back(sccno[v]);
				}
			}
		}
		ans = weight[sccno[1]];
		newdfs(sccno[1], weight[sccno[1]]);
		printf("%d\n", ans);
	}
	return 0;
} 
