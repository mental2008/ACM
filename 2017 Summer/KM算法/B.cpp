#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int n, m;
char ch[maxn][maxn];
struct Point {
	int x, y;
	Point(int _x, int _y) {
		x = _x, y = _y;
	}
};
int sign[maxn][maxn];
bool vis[maxn][maxn];
int p[4] = {1, -1, 0, 0};
int q[4] = {0, 0, 1, -1};
int cnth, cntm;
int a[maxn][maxn];
vector<Point> vec;
vector<Point> vech;
int match[maxn];
int house[maxn];
int people[maxn];
bool vis_house[maxn];
bool vis_people[maxn];
int d;

bool KM_dfs(int i) {
	vis_people[i] = 1;
	for(int j = 1; j <= cnth; j++) {
		if(vis_house[j]) continue;
		int gap = people[i] + house[j] - a[i][j];
		if(gap == 0) {
			vis_house[j] = 1;
			if(match[j] == -1 || KM_dfs(match[j])) {
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
	memset(house, 0, sizeof(house));
	for(int i = 1; i <= cntm; i++) {
		people[i] = a[i][1];
		for(int j = 2; j <= cnth; j++) {
			people[i] = max(people[i], a[i][j]);
		}
	}
	for(int i = 1; i <= cntm; i++) {
		while(1) {
			memset(vis_house, 0, sizeof(vis_house));
			memset(vis_people, 0, sizeof(vis_people));
			d = INF;
			if(KM_dfs(i)) break;
			for(int j = 1; j <= cntm; j++) {
				if(vis_people[j]) people[j] -= d;
				if(vis_house[j]) house[j] += d;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= cnth; i++) {
		ans -= a[match[i]][i];
		//printf("%d %d\n", match[i], i);
	}
	printf("%d\n", ans);
}

int main() {
	while(~scanf("%d%d", &n, &m), n || m) {
		getchar();
		vec.clear();
		vech.clear();
		memset(sign, 0, sizeof(sign));
		memset(a, 0, sizeof(a));
		cnth = 0, cntm = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%c", &ch[i][j]);
				if(ch[i][j] == 'm') {
					Point point(i, j);
					vec.push_back(point);
					sign[i][j] = ++cntm;
				}
				else if(ch[i][j] == 'H') {
					Point point(i, j);
					vech.push_back(point);
					sign[i][j] = ++cnth;
				}
			}
			getchar();
		}
		for(int i = 0; i < vec.size(); i++) {
			for(int j = 0; j < vech.size(); j++) {
				a[sign[vec[i].x][vec[i].y]][sign[vech[j].x][vech[j].y]] = (-1) * (abs(vec[i].x - vech[j].x) + abs(vec[i].y - vech[j].y));
			}
		}
		/*for(int i = 1; i <= cntm; i++) {
			for(int j = 1; j <= cnth; j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}*/
		KM();
	}
	return 0;
}
