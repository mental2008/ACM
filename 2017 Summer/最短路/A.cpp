#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
struct Edge {
	int from, to, dis;
	Edge(int _from, int _to, int _dis) {
		from = _from, to = _to, dis = _dis;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
bool done[maxn];
int d[maxn];
int t, n;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
}

void AddEdge(int from, int to, int dis) {
	edges.push_back(Edge(from, to, dis));
	int k = edges.size();
	G[from].push_back(k - 1);
}

struct HeapNode {
	int d, u;
	bool operator < (const HeapNode &e) const {
		return d > e.d;
	}
};

void dijkstra(int s) {
	priority_queue<HeapNode> q;
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[s] = 0;
	memset(done, 0, sizeof(done));
	q.push((HeapNode){0, s});
	while(!q.empty()) {
		HeapNode x = q.top();
		q.pop();
		int u = x.u;
		if(done[u]) continue;
		done[u] = 1;
		for(int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if(d[e.to] > d[u] + e.dis) {
				d[e.to] = d[u] + e.dis;
				q.push((HeapNode){d[e.to], e.to});
			}
		}
	}
}

int main() {
	while(~scanf("%d%d", &t, &n)) {
		init();
		for(int i = 1; i <= t; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, w);
			AddEdge(v, u, w);
		}
		dijkstra(1);
		printf("%d\n", d[n]);
	}
	return 0;
}
