#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = (1 << 30) - 1;
int n;
int a[maxn][maxn];
int value[maxn];
int fuck[maxn];
int fucked[maxn];
int match[maxn];
bool vis_fuck[maxn];
bool vis_fucked[maxn];
int d;
int slack[maxn];

bool dfs(int i) {
	vis_fuck[i] = 1;
	for(int j = 1; j <= n; j++) {
		if(vis_fucked[j]) continue;
		int gap = fuck[i] + fucked[j] - a[i][j];
		if(gap == 0) {
			vis_fucked[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
		else slack[j] = min(slack[j], gap);
	}
	return false;
}

void KM() {
	memset(match, -1, sizeof(match));
	memset(fucked, 0, sizeof(fucked));
	for(int i = 1; i <= n; i++) {
		fuck[i] = -INF;
		for(int j = 1; j <= n; j++) {
				fuck[i] = max(fuck[i], a[i][j]);
		}
	} 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) slack[j] = INF;
		while(1) {
			memset(vis_fuck, 0, sizeof(vis_fuck));
			memset(vis_fucked, 0, sizeof(vis_fucked));
			if(dfs(i)) break;
			d = INF;
			for(int j = 1; j <= n; j++) {
				if(!vis_fucked[j]) d = min(d, slack[j]);
			}
			if(d == INF) break;
			for(int j = 1; j <= n; j++) {
				if(vis_fuck[j]) fuck[j] -= d;
				if(vis_fucked[j]) fucked[j] += d;
				else slack[j] -= d;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(match[i] != -1) ans += a[match[i]][i];
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d", &n), n) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", &value[i]);
		}
		memset(a, 0, sizeof(a));
		getchar();
		for(int i = 1; i <= n; i++) {
			char s[105];
			scanf("%s", s);
			getchar();
			for(int j = 0; j < n; j++) {
				if(s[j] == '1') {
					a[i][j + 1] = (value[i] ^ value[j + 1]);
				}
			}
		}
		KM();
	}
	return 0;
} 
