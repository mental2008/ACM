#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn = 10005;
int n, m;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn];
int sccno[maxn];
int dfs_clock;
int scc_cnt;
stack<int> s;

void init() {
	for(int i = 0; i < maxn; i++) G[i].clear();
	memset(pre, 0, sizeof(pre));
	memset(lowlink, 0, sizeof(lowlink));
	memset(sccno, 0, sizeof(sccno));
	dfs_clock = scc_cnt = 0;
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
	if(lowlink[u] == pre[u]) {
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
	while(~scanf("%d%d", &n, &m), n || m) {
		init();
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		for(int i = 1; i <= n; i++) {
			if(!pre[i]) dfs(i);
		}
		bool ok = true;
		for(int i = 1; i <= n; i++) {
			if(sccno[i] != 1) {
				ok = false;
				break;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
} 
