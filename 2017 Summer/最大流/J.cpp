#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int n, m, f;
int ans;
int a[maxn][maxn];
int fa[maxn];
int match[maxn];
bool vis_boy[maxn];
bool vis_girl[maxn];
int d;

int find(int x) {
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void connect(int x, int y) {
	int p = find(x);
	int q = find(y);
	//printf("p = %d, q = %d\n", p, q);
	if(p != q) fa[q] = p;
}

bool dfs(int i) {
	vis_girl[i] = 1;
	for(int j = 1; j <= n; j++) {
		if(vis_boy[j]) continue;
		if(a[i][j] == 1) {
			vis_boy[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
	}
	return false;
}

bool judge() {
	memset(match, -1, sizeof(match));
	for(int i = 1; i <= n; i++) {
		memset(vis_girl, 0, sizeof(vis_girl));
		memset(vis_boy, 0, sizeof(vis_boy));
		if(!dfs(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d%d", &n, &m, &f);
		ans = 0;
		for(int i = 0; i < maxn; i++) fa[i] = i;
		memset(a, -1, sizeof(a));
		for(int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
		}
		for(int i = 1; i <= f; i++) {
			int girl1, girl2;
			scanf("%d%d", &girl1, &girl2);
			connect(girl1, girl2);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(find(i) == find(j)) {
					//printf("%d %d\n", i, j);
					for(int k = 1; k <= n; k++) {
						if(a[i][k] == 1) a[j][k] = 1;
						if(a[j][k] == 1) a[i][k] = 1;
					}
				}
			}
		}
		/*for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				printf("i = %d, j = %d, val = %d\n", i, j, a[i][j]);
			}
		}*/
		while(judge()) {
			ans++;
			for(int i = 1; i <= n; i++) {
				a[match[i]][i] = -1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
