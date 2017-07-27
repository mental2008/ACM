#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 15;
int n;
int ans[maxn];
bool vis[maxn][maxn];

bool judge(int x, int y, int k) {
	for(int i = 1; i < x; i++) {
		for(int j = 1; j <= k; j++) {
			if(j == y || x + y == i + j || x - y == i - j) {
				if(vis[i][j]) return false;
			}
		}
	}
	return true;
}

void dfs(int now, int k) {
	if(now == k) ans[k]++;
	for(int i = 1; i <= k; i++) {
		if(judge(now + 1, i, k)) {
			vis[now + 1][i] = 1;
			dfs(now + 1, k);
			vis[now + 1][i] = 0;
		}
	}
}

int main() {
	for(int i = 1; i <= 10; i++) {
		memset(vis, 0, sizeof(vis));
		dfs(0, i);
	}
	while(~scanf("%d", &n), n) {
		printf("%d\n", ans[n]);
	}
	return 0;
} 
