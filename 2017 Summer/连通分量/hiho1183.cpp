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
	bool operator < (const Edge &e) const {
		if(from == e.from) return to < e.to;
		else return from < e.from;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn], low[maxn];
int dfs_clock;
bool cut[maxn];
vector<int> ansnode;
vector<Edge> ansedge;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	memset(cut, 0, sizeof(cut));
	ansnode.clear();
	ansedge.clear();
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
	int child = 0;
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(!pre[v]) {
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if(lowv >= pre[u]) {
				cut[u] = 1;
			}
			if(lowv > pre[u]) {
				edges[G[u][i]].bridge = 1;
				edges[G[u][i] ^ 1].bridge = 1;
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
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}
		dfs(1, -1);
		for(int i = 1; i <= n; i++) {
			if(cut[i]) ansnode.push_back(i);
		}
		if(ansnode.size() == 0) puts("Null");
		else {
			printf("%d", ansnode[0]);
			for(int i = 1; i < ansnode.size(); i++) {
				printf(" %d", ansnode[i]);
			}
			puts("");
		}
		for(int i = 0; i < edges.size(); i++) {
			Edge e = edges[i];
			if(e.bridge && e.from < e.to) {
				ansedge.push_back(e);
			}
		}
		sort(ansedge.begin(), ansedge.end());
		for(int i = 0; i < ansedge.size(); i++) {
			printf("%d %d\n", ansedge[i].from, ansedge[i].to);
		}
	} 
	return 0;
} 
