#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const int INF = (1 << 30) - 1;
int n, m;
struct Edge {
	int from, to, cap, flow;
	Edge(int _from, int _to, int _cap, int _flow) {
		from = _from, to = _to, cap = _cap, flow = _flow;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int a[maxn];
int p[maxn];

void init() {
	for(int i = 1; i <= m; i++) G[i].clear();
	edges.clear();
}

void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

int Maxflow(int s, int t) {
	int flow = 0;
	while(1) {
		memset(a, 0, sizeof(a));
		queue<int> Q;
		Q.push(s);
		a[s] = INF;
		while(!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for(int i = 0; i < G[x].size(); i++) {
				Edge e = edges[G[x][i]];
				if(!a[e.to] && e.cap > e.flow) {
					p[e.to] = G[x][i];
					a[e.to] = min(a[x], e.cap - e.flow);
					Q.push(e.to);
				}
			}
			if(a[t]) break;
		}
		if(!a[t]) break;
		for(int u = t; u != s; u = edges[p[u]].from) {
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
		}
		flow += a[t];
	}
	return flow;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 0; i < n; i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			AddEdge(u, v, c);
		}
		printf("%d\n", Maxflow(1, m));
	}
	return 0;
} 
