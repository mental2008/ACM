#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
const int INF = 0x3f3f3f3f;
int n;
int a[maxn][maxn];
int match[maxn];
int house[maxn];
int people[maxn];
bool vis_house[maxn];
bool vis_people[maxn];
int d;

bool dfs(int i) {
	vis_people[i] = 1;
	for(int j = 1; j <= n; j++) {
		if(vis_house[j]) continue;
		int gap = people[i] + house[j] - a[i][j];
		if(gap == 0) {
			vis_house[j] = 1;
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
	memset(house, 0, sizeof(people));
	for(int i = 1; i <= n; i++) {
		people[i] = a[i][1];
		for(int j = 2; j <= n; j++) {
			people[i] = max(people[i], a[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		while(1) {		
			memset(vis_house, 0, sizeof(vis_house));
			memset(vis_people, 0, sizeof(vis_people));
			d = INF;
			if(dfs(i)) break;
			for(int j = 1; j <= n; j++) {
				if(vis_people[j]) people[j] -= d;
				if(vis_house[j]) house[j] += d;
			}
		} 
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[match[i]][i];
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		KM();
	}
	return 0;
}
