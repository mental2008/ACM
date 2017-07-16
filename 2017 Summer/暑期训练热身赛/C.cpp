#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 2e5 + 100;
LL sum[maxn];
LL old[maxn][2];
bool add[maxn];
int n, m;

struct Node {
	LL x, y;
}node[maxn];

bool cmp(Node a, Node b) {
	return a.x < b.x;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		sum[i] = 1;
		old[i][0] = 0;
		old[i][1] = 0;
		add[i] = false;
	}
	for(int i = 1; i <= m; i++) {
		LL _x, _y;
		scanf("%lld%lld", &_x, &_y);
		node[i].x = _x;
		node[i].y = _y;
	}
	sort(node + 1, node + 1 + m, cmp);
	for(int i = 1; i <= m; i++) {
		int index = node[i].y;
		LL temp = sum[index];
		sum[index] = sum[index] + sum[index + 1] - old[index + 1][1];
		sum[index + 1] = sum[index + 1] + temp - old[index][0];
		old[index][0] = sum[index];
		old[index + 1][1] = sum[index + 1];	
	}
	printf("%d", sum[1]);
	for(int i = 2; i <= n; i++) {
		printf(" %d", sum[i]);
	}
	puts("");
	return 0;
}
