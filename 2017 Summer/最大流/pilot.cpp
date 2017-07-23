#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = (1 << 30) - 1;
int m, n;
int a[maxn][maxn];
int match[maxn];
int english[maxn];
int foreign[maxn];
bool vis_english[maxn];
bool vis_foreign[maxn];
int d;

bool dfs(int i) {
	vis_foreign[i] = 1;
	for(int j = 1; j <= n; j++) {
		if(vis_english[j]) continue;
		int gap = foreign[i] + english[j] - a[i][j];
		if(gap == 0) {
			vis_english[j] = 1;
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
	memset(english, 0, sizeof(english));
	for(int i = 1; i <= m; i++) {
		foreign[i] = 0;
		for(int j = 1; j <= n; j++) {
			foreign[i] = max(foreign[i], a[i][j]);
		}
	}
	for(int i = 1; i <= m; i++) {
		while(1) {
			memset(vis_english, 0, sizeof(vis_english));
			memset(vis_foreign, 0, sizeof(vis_foreign));
			d = INF;
			if(dfs(i)) break;
			if(d == INF) break;
			for(int j = 1; j <= m; j++) if(vis_foreign[j]) foreign[j] -= d;
			for(int j = 1; j <= n; j++) if(vis_english[j]) english[j] += d;
		}
	}
	bool ok = false;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(match[i] != -1) {
			ok = true;
			ans += a[match[i]][i];
		}
	}
	if(ok) printf("%d\n", ans);
	else puts("No Solution!");
}

int main() {
	scanf("%d%d", &m, &n);
	int i, j;
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			a[i][j] = -INF;
		}
	}
	while(~scanf("%d%d", &i, &j)) {
		if(i == -1 && j == -1) break;
		a[i][j - m] = 1;
	}
	n = n - m;
	KM();
	return 0;
}
