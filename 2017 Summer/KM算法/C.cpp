//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 510;
const int INF = (1<<30)-1;
int n, m, q;
int caseCnt;
int a[maxn][maxn];
bool vis[maxn][maxn];
int match[maxn];
int stumap[maxn];
int student[maxn];
int room[maxn];
bool vis_room[maxn];
bool vis_student[maxn];
int d;

bool dfs(int i) {
	vis_student[i] = 1;
	for(int j = 0; j < m; j++) {
		if(!vis[i][j]) continue;
		if(vis_room[j]) continue;
		int gap = student[i] + room[j] - a[i][j];
		if(gap == 0) {
			vis_room[j] = 1;
			if(match[j] == -1 || dfs(match[j])) {
				match[j] = i;
				stumap[i] = j;
				return true;
			}
		}
		else d = min(d, gap);
	}
	return false;
}

void KM() {
	memset(stumap, -1, sizeof(stumap));
	memset(match, -1, sizeof(match));
	memset(room, 0, sizeof(room));
	for(int i = 0; i < n; i++) {
		student[i] = -INF;
		for(int j = 0; j < m; j++) {
			if(vis[i][j]) {
				student[i] = max(student[i], a[i][j]);
			}
		}
		if(student[i] == -INF) {
			puts("-1");
			return;
		}
	}
	for(int i = 0; i < n; i++) {
		while(1) {
			memset(vis_room, 0, sizeof(vis_room));
			memset(vis_student, 0, sizeof(vis_student));
			int d = INF;
			if(dfs(i)) break;
			if(d == INF || d == 0) {
				puts("-1");
				return;
			}
			for(int j = 0; j < n; j++) if(vis_student[j]) student[j] -= d;
			for(int j = 0; j < m; j++) if(vis_room[j]) room[j] += d;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a[i][stumap[i]];
	}
	printf("%d\n", ans);
}

int main() {
	caseCnt = 0;
	while(~scanf("%d%d%d", &n, &m, &q)) {
		caseCnt++;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < q; i++) {
			int s, r, v;
			scanf("%d%d%d", &s, &r, &v);
			if(v < 0) continue;
			a[s][r] = v;
			vis[s][r] = 1;
		}
		printf("Case %d: ", caseCnt);
		KM();
	}
	return 0;
} 
