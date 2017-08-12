#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define mem(a, i) memset(a, i, sizeof(a))
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int m, n;
struct Edge {
	int from, to, cost;
	Edge(int _from, int _to, int _cost) {
		from = _from, to = _to, cost = _cost;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int level[maxn];
int d[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	mem(level, 0);
}

void AddEdge(int from, int to, int cost) {
	edges.push_back(Edge(from, to, cost));
	int k = edges.size();
	G[from].push_back(k - 1);
}

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode& e) const {
		return d > e.d;
	}
};

int dijsktra(int lower) {
	mem(vis, 0);
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[0] = 0;
	priority_queue<HeapNode> q;
	q.push((HeapNode){0, 0});
	while(!q.empty()) {
		HeapNode x = q.top();
		q.pop();
		int u = x.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if(level[e.to] < lower || level[e.to] > (lower + m)) continue;
			if(d[e.to] > d[u] + e.cost) {
				d[e.to] = d[u] + e.cost;
				q.push((HeapNode){d[e.to], e.to});
			}
		}
	}
	return d[1];
}

int main() {
	while(~scanf("%d%d", &m, &n)) {
		init();
		int minx = INF, maxx = 0;
		for(int i = 1; i <= n; i++) {
			int w, rep;
			scanf("%d%d%d", &w, &level[i], &rep);
			minx = min(minx, level[i]);
			maxx = max(maxx, level[i]);
			AddEdge(0, i, w);
			for(int j = 1; j <= rep; j++) {
				int u, cost;
				scanf("%d%d", &u, &cost);
				AddEdge(u, i, cost);
			}
		}
		int ans = INF;
		for(int i = minx; i <= maxx; i++) {
			ans = min(ans, dijsktra(i));
		}
		printf("%d\n", ans);
	}
	return 0;
} 
