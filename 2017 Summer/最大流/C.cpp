#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
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
int p[maxn];
int d[maxn];
int num[maxn];
bool vis[maxn];
int cur[maxn];
int pi[maxn], si[maxn], ei[maxn];

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
	vis[t] = 1;
	d[t] = 0;
	queue<int> Q;
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
	BFS();
	memset(num, 0, sizeof(num));
	for(int i = 1; i <= n; i++) num[d[i]]++;
	int x = s;
	memset(cur, 0, sizeof(cur));
	int flow = 0;
	while(d[s] < n) {
		if(x == t) {
			flow += Augment();
			x = s;
		}
		bool ok = false;
		for(int i = 0; i < G[x].size(); i++) {
			Edge e = edges[G[x][i]];
			if(e.cap > e.flow && d[x] == d[e.to] + 1) {
				ok = 1;
				p[e.to] = G[x][i];
				cur[x] = i;
				x = e.to;
				break;
			}
		}
		if(!ok) {
			int k = n - 1;
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
	int caseCnt;
	scanf("%d", &caseCnt);
	for(int times = 1; times <= caseCnt; times++) {
		int maxt = -INF, mint = INF;
		int need = 0;
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &pi[i], &si[i], &ei[i]);
			maxt = max(maxt, ei[i]);
			mint = min(mint, si[i]);
			AddEdge(1, i + 1, pi[i]);
			need += pi[i];
		}
		for(int i = 1; i <= n; i++) {
			for(int j = si[i]; j <= ei[i]; j++) {
				AddEdge(i + 1, n + 1 + j, 1);
			}
		}
		for(int i = mint; i <= maxt; i++) {
			AddEdge(n + 1 + i, 2 + n + maxt, m);
		}
		n = 2 + n + maxt;
		int result = Maxflow(1, n);
		//printf("need = %d, result = %d\n", need, result);
		if(result == need) printf("Case %d: Yes\n", times);
		else printf("Case %d: No\n", times);
		puts("");
	}
	return 0;
}
