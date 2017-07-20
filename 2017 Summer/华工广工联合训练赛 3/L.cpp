#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 310;
int n;
LL ans;
struct alien {
	LL a, b, d;
	int sign;
}node[maxn];

bool cmp(alien x, alien y) {
	return x.b < y.b;
} 

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &node[i].a, &node[i].b, &node[i].d);
			node[i].sign = false;
		}
		sort(node + 1, node + 1 + n, cmp);
		ans = 0;
		for(int i = 1; i <= n; i++) {
			if(node[i].sign) continue;
			LL temp = node[i].d;
			node[i].sign = true;
			for(int j = 1; j <= n; j++) {
				if(j == i) continue;
				if(node[j].a <= node[i].b && node[j].b >= node[i].b) {
					node[j].sign = true;
					temp = max(temp, node[j].d);
				}
			}
			ans += temp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
