#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1005;
int n, m;
struct Edge {
	int from, to;
	Edge(int _from, int _to) {
		from = _from, to = _to;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
bool hate[maxn][maxn];
int low[maxn], pre[maxn];
int dfs_clock;
int bcc_cnt;
int bccno[maxn];
int odd[maxn];
int color[maxn];
stack<Edge> s;
vector<int> bcc[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	for(int i = 0; i < maxn; i++) bcc[i].clear();
	while(!s.empty()) s.pop();
	edges.clear();
	memset(hate, 0, sizeof(hate));
	memset(low, 0, sizeof(low));
	memset(pre, 0, sizeof(pre));
	memset(bccno, 0, sizeof(bccno));
	memset(odd, 0, sizeof(odd));
	dfs_clock = 0;
	bcc_cnt = 0;
}

void AddEdge(int from, int to) {
	edges.push_back(Edge(from, to));
	edges.push_back(Edge(to, from));
	int k = edges.size();
	G[from].push_back(k - 2);
	G[to].push_back(k - 1);
}

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(!pre[v]) {
			s.push(edges[G[u][i]]);
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if(lowv >= pre[u]) {
				bcc[++bcc_cnt].clear();
				while(1) {
					Edge x = s.top();
					s.pop();
					if(bccno[x.from] != bcc_cnt) {
						bcc[bcc_cnt].push_back(x.from);
						bccno[x.from] = bcc_cnt;
					}
					if(bccno[x.to] != bcc_cnt) {
						bcc[bcc_cnt].push_back(x.to);
						bccno[x.to] = bcc_cnt;
					}
					if(x.from == u && x.to == v) break;
				}
			}
		}
		else if(pre[v] < pre[u] && v != fa) {
			s.push(edges[G[u][i]]);
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

bool bipartite(int u, int b) {
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(bccno[v] != b) continue;
		if(color[v] == color[u]) return false;
		if(!color[v]) {
			color[v] = 3 - color[u];
			if(!bipartite(v, b)) return false;
		}
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m), n || m) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			hate[u][v] = hate[v][u] = 1;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(!hate[i][j]) {
					AddEdge(i, j);
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i, -1);
		}
		for(int i = 1; i <= bcc_cnt; i++) {
			memset(color, 0, sizeof(color));
			for(int j = 0; j < bcc[i].size(); j++) bccno[bcc[i][j]] = i;
			int u = bcc[i][0];
			color[u] = 1;
			if(!bipartite(u, i))
				for(int j = 0; j < bcc[i].size(); j++) odd[bcc[i][j]] = 1;
		}
		int ans = n;
		for(int i = 1; i <= n; i++) if(odd[i]) ans--;
		printf("%d\n", ans);
	}
	return 0;
}
