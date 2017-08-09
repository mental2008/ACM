#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 505;
const int INF = 0x3f3f3f3f;
struct Edge {
	int from, to, dis;
	Edge(int _from, int _to, int _dis) {
		from = _from, to = _to, dis = _dis;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int cnt[maxn];
int n, m, hole;
int inq[maxn];//判断点是否在队列中
int d[maxn];//源点到该点的最短距离

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(cnt, 0, sizeof(cnt));
	memset(inq, 0, sizeof(inq));
}

void AddEdge(int from, int to, int dis) {
	edges.push_back(Edge(from, to, dis));
	int k = edges.size();
	G[from].push_back(k - 1);
}

bool bellman_ford() {
	queue<int> q;
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[0] = 0;
	inq[0] = true;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if(d[u] < INF && d[e.to] > d[u] + e.dis) {
				d[e.to] = d[u] + e.dis;
				if(!inq[e.to]) {
					q.push(e.to);
					inq[e.to] = true;
					if(++cnt[e.to] > n + 1) return false; 
				}
			}
		}
	}
	return true;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		init();
		scanf("%d%d%d", &n, &m, &hole);
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, w);
			AddEdge(v, u, w);
		}
		for(int i = 1; i <= hole; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, -w);
		}
		for(int i = 1; i <= hole; i++) {
			AddEdge(0, i, INF >> 1);
			AddEdge(i, 0, INF >> 1);
		}
		if(bellman_ford()) puts("NO");
		else puts("YES");
	}
	return 0;
}
