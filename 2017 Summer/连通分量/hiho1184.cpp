#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 20010;
const int maxm = 100010;
int n, m;
struct Edge {
	int from, to, bridge;
	Edge(int _from, int _to, int _bridge) {
		from = _from, to = _to, bridge = _bridge;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn], low[maxn];
int dfs_clock;
int bcc[maxn];
bool vis[maxn];
int ans[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	memset(bcc, 0, sizeof(bcc));
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	dfs_clock = 0;
}

void AddEdge(int from, int to) {
	edges.push_back(Edge(from, to, 0));
	edges.push_back(Edge(to, from, 0));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(!pre[v]) {
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if(lowv > pre[u]) {
				edges[G[u][i]].bridge = 1;
				edges[G[u][i] ^ 1].bridge = 1;
			}
		}
		else if(pre[v] < pre[u] && v != fa) {
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

void bcc_dfs(int u, int cnt) {
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(!edges[G[u][i]].bridge && !vis[v]) {
			bcc[v] = cnt;
			vis[v] = 1;
			bcc_dfs(v, cnt);
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}
		dfs(1, -1);
		int cnt = 1;
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) {
				vis[i] = 1;
				bcc[i] = cnt;
				bcc_dfs(i, cnt);
				cnt++;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(ans[bcc[i]] == 0) {
				ans[bcc[i]] = i;
			}
		}
		printf("%d\n", cnt - 1);
		printf("%d", ans[bcc[1]]);
		for(int i = 2; i <= n; i++) {
			printf(" %d", ans[bcc[i]]);
		}
		puts("");
	} 
	return 0;
}
