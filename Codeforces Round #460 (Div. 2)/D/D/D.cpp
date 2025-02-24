// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 3e5 + 5;
int n, m;
int val[maxn];
char ch[maxn];
int head[maxn];
int to[maxn];
int nxt[maxn];
int cnt;
int dp[maxn][30];
int deg[maxn];
int degree[maxn];
queue<int> q;

void AddEdge(int u, int v) {
	to[cnt] = v;
	nxt[cnt] = head[u];
	head[u] = cnt++;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", ch);
	for (int i = 0; i < n; ++i) {
		val[i] = (int)(ch[i] - 'a');
	}
	mem(head, -1);
	mem(nxt, -1);
	mem(to, -1);
	cnt = 0;
	mem(deg, 0);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		AddEdge(u, v);
		deg[v]++;
	}
	mem(dp, 0);
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		while (!q.empty()) q.pop();
		for (int j = 0; j < n; ++j) {
			degree[j] = deg[j];
			if (degree[j] == 0) q.push(j);
		}
		int tot = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (val[u] == i) dp[u][i]++;
			ans = max(ans, dp[u][i]);
			tot++;
			if (tot > n) {
				puts("-1");
				return 0;
			}
			for (int j = head[u]; j != -1; j = nxt[j]) {
				int v = to[j];
				dp[v][i] = max(dp[v][i], dp[u][i]);
				degree[v]--;
				if (degree[v] == 0) {
					q.push(v);
				}
			}
		}
		if (tot != n) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
