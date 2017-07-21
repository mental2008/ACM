#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int INF = (1 << 30) - 1;
int n, m, k;
int a[maxn][maxn];
map<string, int> lvbu;
map<string, int> cao;
int match[maxn];
int lb[maxn];
int cc[maxn];
bool vis_lb[maxn];
bool vis_cc[maxn];
//int slack[maxn];
int d;

bool dfs(int i) {
	vis_lb[i] = 1;
	for(int j = 1; j <= m; j++) {
		if(vis_cc[j]) continue;
		int gap = lb[i] + cc[j] - a[i][j];
		if(gap == 0) {
			vis_cc[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				return true;
			}
		}
//		else slack[j] = min(slack[j], gap);
		else d = min(d, gap);
	} 
	return false;
}

void KM() {
	memset(match, -1, sizeof(match));
	memset(cc, 0, sizeof(cc));
	for(int i = 1; i <= n; i++) {
		lb[i] = -INF;
		for(int j = 1; j <= m; j++) {
			lb[i] = max(lb[i], a[i][j]);
		}
//		printf("%d\n", lb[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) slack[j] = INF;
		while(1) {
			memset(vis_lb, 0, sizeof(vis_lb)),
			memset(vis_cc, 0, sizeof(vis_cc));
			d = INF;	
			if(dfs(i)) break;
//			for(int j = 1; j <= m; j++) {
//				if(!vis_cc[j]) d = min(d, slack[j]);
//			}
			for(int j = 1; j <= n; j++) {
				if(vis_lb[j]) lb[j] -= d;
			}
			for(int j = 1; j <= m; j++) {
				if(vis_cc[j]) cc[j] += d;
//				else slack[j] -= d;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		if(match[i] != -1) {
			ans -= a[match[i]][i];
		}
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d%d%d", &n, &m, &k)) {
		lvbu.clear(), cao.clear();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				a[i][j] = -INF;
			}
		}
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= k; i++) {
			char s1[25], s2[25];
			scanf("%s %s", &s1, &s2);
			int value;
			scanf("%d", &value);
			
			if(lvbu[s1] == 0) {
				lvbu[s1] = ++cnt1;
			}
			if(cao[s2] == 0) {
				cao[s2] = ++cnt2;
			}
			
			a[lvbu[s1]][cao[s2]] = -value;
//			printf("%d %d %d\n", pos1, pos2, -value);
		}
		KM();
	}
	return 0;
}
