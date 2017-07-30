#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 100005;
int n, k;
struct Edge {
	int u, v, value;
} edge[maxn];
int machine[maxn];
int fa[maxn];

bool cmp(Edge x, Edge y) {
	return x.value > y.value;
}

void init() {
	memset(machine, 0, sizeof(machine));
	for(int i = 0; i < maxn; i++) fa[i] = i;
}

int find(int x) {
	return (fa[x] == x ? x : (fa[x] = find(fa[x])));
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		init();
		scanf("%d%d", &n, &k);
		LL sum = 0;
		for(int i = 1; i < n; i++) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].value);
			sum += edge[i].value;
		}
		sort(edge + 1, edge + n, cmp);
		for(int i = 1; i <= k; i++) {
			int x;
			scanf("%d", &x);
			machine[x] = 1;
		}
		LL ans = 0;
		for(int i = 1; i < n; i++) {
			int u = edge[i].u, v = edge[i].v;
			int fa_u = find(u), fa_v = find(v);
			if(machine[fa_u] && machine[fa_v]) continue;
			else {
				fa[fa_u] = fa_v;
				if(machine[fa_u] || machine[fa_v]) {
					machine[fa_u] = machine[fa_v] = 1;
					machine[u] = machine[v] = 1;
				}
				ans += edge[i].value;
			}
		}
		printf("%lld\n", sum - ans);
	}
	return 0;
}
