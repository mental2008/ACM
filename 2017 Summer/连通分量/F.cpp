#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn = 1005;
int n, m;
struct Edge {
	int from, to;
	Edge(int _from, int _to) {
		from = _from, to = _to;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn], low[maxn];
int dfs_clock;
int cut[maxn];
bool root[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	dfs_clock = 0;
	memset(cut, 0, sizeof(cut));
	memset(root, 0, sizeof(root));
}

void AddEdge(int from, int to) {
	edges.push_back(Edge(from, to));
	edges.push_back(Edge(to, from));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(!pre[v]) {
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if(lowv >= pre[u]) {
				cut[u]++;
			}
		}
		else if(pre[v] < pre[u] && v != fa) {
			lowu = min(lowu, pre[v]);
		}
	}
	if(fa < 0 && child == 1) cut[u] = 0;
	low[u] = lowu;
	return lowu;
}

int main() {
	int u, v;
	int caseCnt = 0;
	while(scanf("%d", &u), u) {
		scanf("%d", &v);
		n = -1;
		init();
		AddEdge(u, v);
		n = max(max(u, n), v);
		while(scanf("%d", &u), u) {
			scanf("%d", &v);
			AddEdge(u, v);
			n = max(max(u, n), v);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i, -1), root[i] = 1;
		}
		printf("Network #%d\n", ++caseCnt);
		bool ok = false;
		for(int i = 1; i <= n; i++) {
			if(cut[i]) {
				ok = true;
				printf("  SPF node %d leaves %d subnets\n", i, (root[i] ? cut[i] : cut[i] + 1));
			}
		}
		if(!ok) puts("  No SPF nodes");
		puts("");
	}
	return 0;
}
