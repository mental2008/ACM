#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
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
int value[maxn];
int vol[15];

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
		memset(value, 0, sizeof(value));
		for(int i = 1; i <= n; i++) {
			int res = 0;
			for(int j = 0; j < m; j++) {
				int temp;
				scanf("%d", &temp);
				res = res * 2 + temp;
			}
			value[res]++;
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d", &vol[i]);
		}
		if(value[0]) puts("NO");
		else {
			init();
			for(int i = 1; i < pow(2, m); i++) {
				AddEdge(0, i, value[i]);
				for(int j = m - 1; j >= 0; j--) {
					if((i >> j) & 1) {
						AddEdge(i, pow(2, m) - 1 + m - j, INF);
					}
				}
			}
			int tempt = pow(2, m) + m;
			for(int i = 1; i <= m; i++) {
				AddEdge(pow(2, m) - 1 + i, tempt, vol[i]);
			}
			int result = Maxflow(0, tempt);
			if(result == n) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
