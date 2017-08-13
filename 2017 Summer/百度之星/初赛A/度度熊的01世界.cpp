#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int n, m;
char ch[maxn][maxn];
int vis[maxn][maxn];
int p[4] = {1, -1, 0, 0};
int q[4] = {0, 0, 1, -1};
int num0, num1;
bool temp[maxn][maxn];
bool sign[maxn * maxn];

void dfs(int i, int j, int cnt) {
	for(int t = 0; t < 4; t++) {
		int x = i + p[t];
		int y = j + q[t];
		if(x < 0 || x >= n || y < 0 || y >= m) continue;
		if(vis[x][y]) continue;
		if(ch[i][j] != ch[x][y]) continue;
		vis[x][y] = cnt;
		dfs(x, y, cnt);
	}
}

bool dfs0(int i, int j) {
	if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
		sign[vis[i][j]] = 1;
		return false;
	}
	for(int t = 0; t < 4; t++) {
		int x = i + p[t];
		int y = j + q[t];
		if(x < 0 || x >= n || y < 0 || y >= m) continue;
		if(temp[x][y] || ch[x][y] == '1') continue;
		temp[x][y] = 1;
		if(!dfs0(x, y)) return false;
	}
	return true;
}

int judge() {
	if(num1 != 1) return -1;
	int sum = 0;
	mem(temp, 0);
	mem(sign, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(sign[vis[i][j]] == 1) continue;
			if(!temp[i][j] && ch[i][j] == '0') {
				temp[i][j] = 1;
				if(dfs0(i, j)) sum++;
			}
		}
	}
//	printf("%d\n", sum);
	if(sum == 1) return 0;
	else if(sum == 0) return 1;
	else return -1;
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i < n; i++) {
			scanf("%s", ch[i]);
		}
		mem(vis, 0);
		int cnt = 0;
		num0 = 0, num1 = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(vis[i][j] == 0) {
					vis[i][j] = ++cnt;
					if(ch[i][j] == '1') num1++;
					else num0++;
					dfs(i, j, cnt);
				}
			}
		}
		printf("%d\n", judge());
	}
	return 0;
}
