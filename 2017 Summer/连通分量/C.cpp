#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 1005;
int n, m;
struct Edge {
	int from, to, cost;
	Edge(int _from, int _to, int _cost) {
		from = _from, to = _to, cost = _cost;
	}
};
vector<Edge> edges;
vector<int> vec[maxn];
int pre[maxn], low[maxn];
int dfs_clock;
bool bridge[maxn * maxn];
bool vis[maxn][maxn];
bool sign[maxn][maxn];
int ans;
int father[maxn];

void init() {
	for(int i = 0; i < maxn; i++) vec[i].clear();
	edges.clear();
	memset(bridge, 0, sizeof(bridge));
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	memset(sign, 0, sizeof(sign));
	dfs_clock = 0;
	ans = -1;
	for(int i = 0; i < maxn; i++) father[i] = i;
}

void AddEdge(int from, int to, int cost) {
	edges.push_back(Edge(from, to, cost));
	edges.push_back(Edge(to, from, cost));
	if(vis[from][to] || vis[to][from]) {
		sign[from][to] = 1;
		sign[to][from] = 1;
	}
	vis[from][to] = 1;
	vis[to][from] = 1;
	int k = edges.size();
	vec[from].push_back(k - 2);
	vec[to].push_back(k - 1);
}

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	for(int i = 0; i < vec[u].size(); i++) {
		int v = edges[vec[u][i]].to;
		if(!pre[v]) {
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if(low[v] > pre[u]) {
				if(!sign[u][v] && !sign[v][u]) {
					if(ans == -1) ans = edges[vec[u][i]].cost;
					else ans = min(ans, edges[vec[u][i]].cost);	
				}
				bridge[vec[u][i]] = 1;
				bridge[vec[u][i] ^ 1] = 1;
			}
		}
		else if(pre[v] < pre[u] && v != fa) {
			lowu = min(lowu, pre[v]);
		}
	}
	low[u] = lowu;
	return lowu;
}

int _find(int x) {
	return (father[x] == x ? x : father[x] = _find(father[x]));
}

void connect(int x, int y) {
	int p = _find(x);
	int q = _find(y);
	if(p != q) father[p] = q; 
}

bool judge() {
	for(int i = 1; i < n; i++) {
		if(_find(i) != _find(i + 1)) return false;
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m), n || m) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, w);
			connect(u, v);
		}
		if(!judge()) {
			puts("0");
			continue;
		}
		dfs(1, 1);
		if(ans == 0) puts("1");
		else printf("%d\n", ans);
	}
	return 0;
} 
/*
这题目很社会
需要特判是否连通
没有守卫也要派出一个士兵
还可能有重边 
*/ 
