#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
int n, m, s, t;
struct Edge {
	int from, to, cap, flow;
	Edge(int _from, int _to, int _cap, int _flow) {
		from = _from, to = _to, cap = _cap, flow = _flow;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int p[maxn];
int d[maxn];
int num[maxn];
bool vis[maxn];
int cur[maxn];

int produce[maxn];
int proNum[maxn];
int cost[maxn];
int sellNum[maxn];
int dis[maxn][maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
}

void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

void BFS() {
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < maxn; i++) d[i] = INF;
	queue<int> Q;
	vis[t] = 1;
	d[t] = 0;
	Q.push(t);
	while(!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i] ^ 1];
			if(!vis[e.from] && e.cap > e.flow) {
				vis[e.from] = 1;
				d[e.from] = d[x] + 1;
				Q.push(e.from);
			}
		}
	}
}

int Augment() {
	int x = t, a = INF;
	while(x != s) {
		Edge e = edges[p[x]];
		a = min(a, e.cap - e.flow);
		x = e.from;
	}
	x = t;
	while(x != s) {
		edges[p[x]].flow += a;
		edges[p[x] ^ 1].flow -= a;
		x = edges[p[x]].from;
	}
	return a;
}

int Maxflow(int u, int v) {
	s = u, t = v;
	memset(num, 0, sizeof(num));
	memset(cur, 0, sizeof(cur));
	BFS();
	for(int i = 0; i <= t; i++) if(d[i] < INF) num[d[i]]++;
	int flow = 0, x = s;
	while(d[x] <= t) {
		if(x == t) {
			flow += Augment();
			x = s;
		}
		bool ok = false;
		for(int i = cur[x]; i < G[x].size(); i++) {
			Edge e = edges[G[x][i]];
			if(e.cap > e.flow && d[x] == d[e.to] + 1) {
				ok = true;
				p[e.to] = G[x][i];
				cur[x] = i;
				x = e.to;
				break;
			}
		}
		if(!ok) {
			int k = t;
			for(int i = 0; i < G[x].size(); i++) {
				Edge e = edges[G[x][i]];
				if(e.cap > e.flow) k = min(k, d[e.to]);
			}
			if(--num[d[x]] == 0) break;
			num[d[x] = k + 1]++;
			cur[x] = 0;
			if(x != s) x = edges[p[x]].from;
		}
	}
	return flow;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &produce[i], &proNum[i], &cost[i], &sellNum[i]);
		}
		for(int i = 1; i < maxn; i++) {
			for(int j = 1; j < maxn; j++) {
				if(i == j) dis[i][j] = 0;
				else dis[i][j] = INF;
			}
		}
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			dis[u][v] = min(dis[u][v], w);
			dis[v][u] = min(dis[v][u], w);
		}
		for(int k = 1; k <= n; k++) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(dis[i][j] > dis[i][k] + dis[k][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}//floyd
	}
	return 0;
} 
