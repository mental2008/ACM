// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 505;
int n, m;
char ch[maxn][maxn];
bool vis[maxn][maxn][2];
int p[4] = { 1, -1, 0, 0 };
int q[4] = { 0, 0, 1, -1 };

struct Node {
	int x, y;
	bool key;
	int step;
	Node(int _x, int _y, bool _key, int _step) {
		x = _x, y = _y, key = _key, step = _step;
	}
};

int BFS() {
	queue<Node> Q;
	while (!Q.empty()) Q.pop();
	mem(vis, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ch[i][j] == 'S') {
				vis[i][j][0] = 1;
				Q.push({i, j, false, 0});
			}
		}
	}
	while (!Q.empty()) {
		Node u = Q.front();
		Q.pop();
		if (ch[u.x][u.y] == 'E') {
			return u.step;
		}
		for (int i = 0; i < 4; ++i) {
			int xx = u.x + p[i];
			int yy = u.y + q[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			bool _key;
			if (ch[xx][yy] == 'K') _key = true;
			else _key = u.key;
			if (ch[xx][yy] == 'W') continue;
			if (ch[xx][yy] == 'D' && _key == false) continue;
			if (vis[xx][yy][_key]) continue;
			vis[xx][yy][_key] = 1;
			Q.push({ xx, yy, _key, u.step + 1 });
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", ch[i]);
	printf("%d\n", BFS());
    return 0;
}

