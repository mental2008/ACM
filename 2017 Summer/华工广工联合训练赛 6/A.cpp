#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 120;
int n, m;
char s[maxn][maxn];
int sum;
int cnt;
struct window {
	int sign;
	int row, col;
	char win[maxn][maxn];
	void clear() {
		sign = 0;
		row = col = 0;
	}
	void print() {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				printf("%c", win[i][j]);
			}
			puts("");
		}
	}
} node[maxn * maxn];
bool vis[maxn][maxn];
int p[4] = {1, -1, 0, 0};
int q[4] = {0, 0, 1, -1};

void dfs(int x, int y, int now, int beginx, int beginy) {
	node[now].win[x - beginx][y - beginy] = s[x][y];
	node[now].row = max(node[now].row, x - beginx + 1);
	node[now].col = max(node[now].col, y - beginy + 1);
	for(int i = 0; i < 4; i++) {
		int xx = x + p[i];
		int yy = y + q[i];
		if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		if(s[xx][yy] != '#' && !vis[xx][yy]) {
			vis[xx][yy] = 1;
			dfs(xx, yy, now, beginx, beginy);
		}
	}
}

void tranverse(char a[maxn][maxn], int r, int c, int now) {
	char b[maxn][maxn];
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < r; j++) {
			b[i][j] = a[r - 1 - j][i];
		}
	}
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < r; j++) {
			node[now].win[i][j] = b[i][j];
		}
	}
	node[now].row = c;
	node[now].col = r;
}

bool compare(char a[maxn][maxn], char b[maxn][maxn], int r, int c) {
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		cnt = sum = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < maxn * maxn; i++) node[i].clear();
		for(int i = 0; i < n; i++) {
			scanf("%s", s[i]);
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i][j] == '#') continue;
				if(vis[i][j]) continue;
				vis[i][j] = 1;
				dfs(i, j, ++sum, i, j);
			}
		}
		/*for(int i = 1; i <= sum; i++) {
			node[i].print();
			puts("");
		}*/
		for(int i = 1; i <= sum; i++) {
			if(node[i].sign) continue;
			node[i].sign = ++cnt;
			for(int j = i + 1; j <= sum; j++) {
				if(node[j].sign) continue;
				for(int k = 0; k < 4; k++) {
					bool ok = false;
					if(node[i].row == node[j].row && node[i].col == node[j].col) {
						if(compare(node[i].win, node[j].win, node[i].row, node[i].col)) ok = true;
					}
					if(ok) {
						node[j].sign = node[i].sign;
						break;
					}
					//node[i].print();
					//puts("");
					if(k != 3) tranverse(node[i].win, node[i].row, node[i].col, i);
				}
				//return 0;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
