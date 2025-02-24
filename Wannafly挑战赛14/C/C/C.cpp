// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

struct Edge {
	int from, to;
	Edge(int _from, int _to) {
		from = _from, to = _to;
	}
};

vector<int> G[maxn], bcc[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void dfs(int u) {
	pre[u] = lowlink[u] = ++dfs_clock;
	S.push(u);
	int len = G[u].size();
	for (int i = 0; i < len; ++i) {
		int v = G[u][i];
		if (!pre[v]) {
			dfs(v);
			lowlink[u] = min(lowlink[v], lowlink[u]);
		}
		else if (!sccno[v]) {
			lowlink[u] = min(lowlink[u], pre[v]);
		}
	}
	if (lowlink[u] == pre[u]) {
		scc_cnt++;
		for (;;) {
			int x = S.top();
			S.pop();
			sccno[x] = scc_cnt;
			if (x == u) break;
		}
	}
}

int in[maxn];
int res[maxn];
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			G[i].clear();
		}
		memset(pre, 0, sizeof(pre));
		memset(sccno, 0, sizeof(sccno));
		dfs_clock = scc_cnt = 0;
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
		}
		for (int i = 1; i <= n; ++i) {
			if (!pre[i]) dfs(i);
		}
		memset(in, 0, sizeof(in));
		ans.clear();
		memset(res, 0x3f, sizeof(res));
		for (int i = 1; i <= n; ++i) {
			int len = G[i].size();
			res[sccno[i]] = min(res[sccno[i]], i);
			for (int j = 0; j < len; ++j) {
				int v = G[i][j];
				if (sccno[i] != sccno[v]) {
					in[sccno[v]]++;
				}
			}
		}
		int temp = 0;
		for (int i = 1; i <= scc_cnt; ++i) {
			if (in[i] == 0) {
				temp++;
				ans.push_back(res[i]);
			}
		}
		sort(ans.begin(), ans.end());
		cout << temp << '\n';
		for (int i = 0; i < temp; ++i) {
			cout << ans[i];
			if (i == temp - 1) cout << '\n';
			else cout << ' ';
		}
	}
    return 0;
}

