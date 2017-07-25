#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 5010;
const int INF = (1 << 30) - 1;
int n, m;
struct Edge {
	int from, to;
	Edge(int _from, int _to) {
		from = _from, to = _to;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
bool bridge[2 * maxn];
int pre[maxn], low[maxn];
int dfs_clock;
int bcc[maxn];
int in[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(vis, 0, sizeof(vis));
	memset(bridge, 0, sizeof(bridge));
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	dfs_clock = 0;
	memset(bcc, 0, sizeof(bcc));
	memset(in, 0, sizeof(in));
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
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if(low[v] > pre[u]) {
				bridge[G[u][i]] = 1;
				bridge[G[u][i] ^ 1] = 1;
			}
		}
		else if(pre[v] < pre[u] && v != fa) {
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

int bcc_dfs(int u, int sign) {
	for(int i = 0; i < G[u].size(); i++) {
		int v = edges[G[u][i]].to;
		if(vis[v]) continue;
		if(bridge[G[u][i]]) continue;
		vis[v] = 1;
		bcc[v] = sign;
		bcc_dfs(v, sign);
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			AddEdge(a, b);
			//AddEdge(b, a);
		}
		dfs(1, 1);
		int cnt = 1;
		for(int i = 1; i <= n; i++) {
			if(vis[i]) continue;
			vis[i] = 1;
			bcc[i] = cnt;
			bcc_dfs(i, cnt);
			cnt++;
		}
		/*for(int i = 1; i <= n; i++) {
			printf("bcc[%d] = %d\n", i, bcc[i]);
		}*/
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < G[i].size(); j++) {
				int v = edges[G[i][j]].to;
				//printf("bcc[%d] = %d bcc[%d] = %d\n", i, bcc[i], v, bcc[v]);
				if(bcc[v] != bcc[i]) {
					in[bcc[i]]++;
				}
			}
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(in[i] == 1) ans++;
		}
		printf("%d\n", ans / 2);
	}
	return 0;
}
