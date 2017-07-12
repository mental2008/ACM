#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define LL long long
#define maxm 1000100
#define maxn 100100
using namespace std;
struct node {
	int point, dx, dy;
	node(int _point, int _dx, int _dy) {
		point = _point, dx = _dx, dy = _dy;
	}
};
vector<node> vec[maxn];
int n, m;
int vis[maxn];
LL x[maxn];
LL y[maxn];

void dfs(int i) {
	for(int j = 0; j < vec[i].size(); j++) {
		node node0 = vec[i][j];
		if(vis[node0.point] == 0) {
			vis[node0.point] = 1;
			x[node0.point] = x[i] + node0.dx;
			y[node0.point] = y[i] + node0.dy;
			dfs(node0.point);
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 0; i < maxn; i++) vec[i].clear();
		for(int i = 1; i <= m; i++) {
			int ai, bi, dxi, dyi;
			scanf("%d%d%d%d", &ai, &bi, &dxi, &dyi);
			vec[ai].push_back(node(bi, dxi, dyi));
			vec[bi].push_back(node(ai, -dxi, -dyi));
		}
		memset(vis, 0, sizeof(vis));
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		vis[1] = 1;
		x[1] = 0, y[1] = 0;
		dfs(1);
		LL minx = x[1], maxx = x[1];
		LL miny = y[1], maxy = y[1];
		for(int i = 2; i <= n; i++) {
			minx = min(minx, x[i]);
			maxx = max(maxx, x[i]);
			miny = min(miny, y[i]);
			maxy = max(maxy, y[i]);
		}
		if(maxx > 1000000000) {
			LL res = maxx - 1000000000;
			for(int i = 1; i <= n; i++) {
				x[i] -= res;
			}
		}
		if(minx < -1000000000) {
			LL res = -1000000000 - minx;
			for(int i = 1; i <= n; i++) {
				x[i] += res;
			}
		}
		if(maxy > 1000000000) {
			LL res = maxy - 1000000000;
			for(int i = 1; i <= n; i++) {
				y[i] -= res;
			}
		}
		if(miny < -1000000000) {
			LL res = -1000000000 - miny;
			for(int i = 1; i <= n; i++) {
				y[i] += res;
			}
		}
		for(int i = 1; i <= n; i++) {
			printf("%lld %lld\n", x[i], y[i]);
		}
	}
	return 0;
}
