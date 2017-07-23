#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int INF = (1 << 30) - 1;
int n, m, s, t;
struct Edge {
	int from, to, cap, flow;
	Edge(int _from, int _to, int _cap, int _flow) {
		from = _from, to = _to, cap = _cap, flow = _flow;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn];
int cur[maxn];

void init() {
	for(int i = 0; i <= m; i++) G[i].clear();
	edges.clear();
}

void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

bool BFS() {
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	Q.push(s);
	d[s] = 0;
	vis[s] = 1;
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i]];
			if(!vis[e.to] && e.cap > e.flow) {
				vis[e.to] = 1;
				d[e.to] = d[x] + 1;
				Q.push(e.to);
			}
		}
	}
	return vis[t];
}

int DFS(int x, int a) {
	if(x == t || a == 0) return a;
	int flow = 0, f;
	for(int& i = cur[x]; i < G[x].size(); i++) {
		Edge& e = edges[G[x][i]];
		if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
			e.flow += f;
			edges[G[x][i] ^ 1].flow -= f;
			flow += f;
			a -= f;
			if(a == 0) break;
		}
	}
	return flow;
}

int Maxflow(int u, int v) {
	s = u, t = v;
	int flow = 0;
	while(BFS()) {
		memset(cur, 0, sizeof(cur));
		flow += DFS(u, INF);
	}
	return flow;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= n; i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			AddEdge(u, v, c);
		}
		printf("%d\n", Maxflow(1, m));
	}
}
