#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int INF = 0x3f3f3f3f;
int n, m;
int s, t;
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
int si[maxn];
int ei[maxn];
int ni[maxn];
int ti[maxn];
int seg[maxn];

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
	memset(d, -1, sizeof(d));
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
	for(int i = 0; i <= t; i++) if(d[i] != -1) num[d[i]]++;
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
		init();
		int need = 0;
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d%d", &si[i], &ni[i], &ei[i], &ti[i]);
			need += (ni[i] * ti[i]);
			AddEdge(0, i, ni[i] * ti[i]);
			seg[cnt++] = si[i];
			seg[cnt++] = ei[i];
		}
		sort(seg, seg + cnt);
		cnt = unique(seg, seg + cnt) - seg;
		for(int i = 1; i < cnt; i++) {
			AddEdge(i + n, n + cnt, (seg[i] - seg[i - 1]) * m);
			for(int j = 1; j <= n; j++) {
				if(si[j] <= seg[i - 1] && ei[j] >= seg[i]) {
					AddEdge(j, i + n, INF);
				}
			}
		}
		int result = Maxflow(0, n + cnt);
		if(result == need) puts("Yes");
		else puts("No");
	}
	return 0;
}
