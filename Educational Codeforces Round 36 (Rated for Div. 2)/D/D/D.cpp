// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 505;
const int maxm = 1e5 + 5;
int n, m;
bool vis[maxn][maxn];
bool ok;
bool sign[maxn];
int pre[maxn];
int dfs_clock;
int head[maxn];
int nxt[maxm];
int to[maxm];
int cnt;

void dfs(int u) {
	pre[u] = ++dfs_clock;
	sign[u] = 1;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (!vis[u][v]) continue;
		if (!pre[v]) {
			dfs(v);
		}
		else if (pre[v] < pre[u] && sign[v] == 1) {
			ok = false;
		}
	}
	sign[u] = 0;
	return;
}

void AddEdge(int u, int v) {
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

int main() {
	scanf("%d%d", &n, &m);
	mem(head, -1);
	mem(nxt, -1);
	mem(to, -1);
	cnt = 0;
	mem(vis, 0);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		vis[u][v] = 1;
		AddEdge(u, v);
	}
	bool ans = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; ~j; j = nxt[j]) {
			int v = to[j];
			vis[i][v] = 0;
			ok = true;
			mem(sign, 0);
			mem(pre, 0);
			dfs_clock = 0;
			for (int k = 1; k <= n; ++k) {
				if (!pre[k]) dfs(k);
			}
			if (ok) {
				ans = true;
				break;
			}
			vis[i][v] = 1;
		}
		if (ans) break;
	}
	if (ans) puts("YES");
	else puts("NO");
	return 0;
}

