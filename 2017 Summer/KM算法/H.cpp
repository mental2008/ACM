#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int INF = (1 << 30) - 1;
int n, m;
int a[maxn][maxn];
int match[maxn];
int from[maxn];
int to[maxn];
bool vis_from[maxn];
bool vis_to[maxn];
int d;

bool dfs(int i) {
	vis_from[i] = 1;
	for(int j = 1; j <= n; j++) {
		if(vis_to[j]) continue;
		int gap = from[i] + to[j] - a[i][j];
		if(gap == 0) {
			vis_to[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
		else d = min(d, gap);
	}
	return false;
}

void KM() {
	memset(match, -1, sizeof(match));
	memset(to, 0, sizeof(to));
	for(int i = 1; i <= n; i++) {
		from[i] = -INF;
		for(int j = 1; j <= n; j++) {
			from[i] = max(from[i], a[i][j]);
		}
		if(from[i] == -INF) {
			puts("-1");
			return;
		}
	}
	for(int i = 1; i <= n; i++) {
		while(1) {
			memset(vis_from, 0, sizeof(vis_from));
			memset(vis_to, 0, sizeof(vis_to));
			d = INF;
			if(dfs(i)) break;
			for(int j = 1; j <= n; j++) {
				if(vis_from[j]) from[j] -= d;
				if(vis_to[j]) to[j] += d;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(match[i] == -1) {
			puts("-1");
			return;
		}
		else ans -= a[match[i]][i];
	}
	printf("%d\n", ans);
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				a[i][j] = -INF;
			}
		}
		for(int i = 1; i <= m; i++) {
			int u, v, value;
			scanf("%d%d%d", &u, &v, &value);
			a[u][v] = max(a[u][v], -value);
		}
		KM();
	}
	return 0;
} 
