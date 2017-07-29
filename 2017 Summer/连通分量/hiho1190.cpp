#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 100005;
const int INF = 0x3f3f3f3f;
struct Edge {
	int from, to, sign;
	Edge(int _from, int _to, int _sign) {
		from = _from, to = _to, sign = _sign;
	}
};
vector<Edge> edges;
vector<int> G[maxn];
int pre[maxn], low[maxn];
int bccno[maxn];
vector<int> bcc[maxn];
int dfs_clock;
int bcc_cnt;
stack<Edge> s;
int n, m;
int ans[maxn];
vector<int> belong[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	edges.clear();
	memset(pre, 0, sizeof(pre));
	memset(low, 0, sizeof(low));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	while(!s.empty()) s.pop();
	for(int i = 0; i < maxn; i++) ans[i] = INF;
	for(int i = 0; i < maxn; i++) belong[i].clear();
}

void AddEdge(int from, int to, int sign) {
	edges.push_back(Edge(from, to, sign));
	edges.push_back(Edge(to, from, sign));
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
					belong[bcc_cnt].push_back(x.sign);
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
	while(~scanf("%d%d", &n, &m)) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v, i);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i, -1);
		}
		for(int i = 1; i <= bcc_cnt; i++) {
			int temp = INF;
			for(int j = 0; j < belong[i].size(); j++) {
				temp = min(temp, belong[i][j]);
			}
			for(int j = 0; j < belong[i].size(); j++) {
				ans[belong[i][j]] = temp;
			}
		}
		printf("%d\n%d", bcc_cnt, ans[1]);
		for(int i = 2; i <= m; i++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}
