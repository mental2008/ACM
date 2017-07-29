#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 20005;
int n, m;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn];
int sccno[maxn];
int dfs_clock;
int scc_cnt;
stack<int> s;
int in[maxn], out[maxn];

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	memset(pre, 0, sizeof(pre));
	memset(lowlink, 0, sizeof(lowlink));
	memset(sccno, 0, sizeof(sccno));
	dfs_clock = scc_cnt = 0;
	while(!s.empty()) s.pop();
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
}

void dfs(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	s.push(u);
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(!pre[v]) {
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if(!sccno[v]) {
			lowlink[u] = min(lowlink[u], pre[v]);
		}
	}
	if(pre[u] == lowlink[u]) {
		scc_cnt++;
		while(1) {
			int x = s.top();
			s.pop();
			sccno[x] = scc_cnt;
			if(x == u) break;
		}
	}
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d", &n, &m);
		init(); 
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < G[i].size(); j++) {
				int v = G[i][j];
				if(sccno[i] != sccno[v]) {
					out[sccno[i]]++;
					in[sccno[v]]++;
				}
			}
		}
		int a, b = a = 0;
		for(int i = 1; i <= scc_cnt; i++) {
			if(!in[i]) a++;
			if(!out[i]) b++;
		}
		int ans = max(a, b);
		if(scc_cnt == 1) puts("0");
		else printf("%d\n", ans); 
	}
	return 0;
}
