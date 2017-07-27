#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 10100;
int n, m;
struct Edge {
	int from, to;
	Edge(int _from, int _to) {
		from = _from, to = _to;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn], low[maxn];
stack<Edge> s;
int dfs_clock;
int bcc_cnt;
int bccno[maxn];
vector<int> bcc[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	for(int i = 0; i < maxn; i++) bcc[i].clear();
	edges.clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	while(!s.empty()) s.pop();
	dfs_clock = bcc_cnt = 0;
	memset(bccno, 0, sizeof(bccno));
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
			lowu = min(lowv, lowu);
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

int main() {
	while(~scanf("%d%d", &n, &m), n || m) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i, -1);
		}
		int ans1 = 0, ans2 = 0;
		for(int i = 1; i <= bcc_cnt; i++) {
			for(int j = 0; j < bcc[i].size(); j++) bccno[bcc[i][j]] = i;
			int cntNode = bcc[i].size();
			int cntEdge = 0;
			for(int j = 0; j < bcc[i].size(); j++) {
				for(int k = 0; k < G[bcc[i][j]].size(); k++) {
					int v = edges[G[bcc[i][j]][k]].to;
					if(bccno[v] != i) continue;
					cntEdge++;
				}
			}
			cntEdge /= 2;
			if(cntEdge > cntNode) ans2 += cntEdge;
			else if(cntEdge < cntNode) ans1 += cntEdge;
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
