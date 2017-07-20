#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1100;
int n;

LL gcd(LL q, LL p) {
	return (p == 0 ? q : gcd(p, q % p));
}

struct wheel {
	LL a, b, sign;
	LL x, y, r;
}node[maxn];
queue<wheel> que;

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d", &n);
		while(!que.empty()) que.pop();
		for(int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &node[i].x, &node[i].y, &node[i].r);
			node[i].sign = 0;
		}
		node[1].sign = 1, node[1].a = 1, node[1].b = 1;
		que.push(node[1]);
		while(!que.empty()) {
			wheel wheel0 = que.front();
			que.pop();
			for(int i = 1; i <= n; i++) {
				if(node[i].sign == 0) {
					if((wheel0.x - node[i].x) * (wheel0.x - node[i].x) + (wheel0.y - node[i].y) * (wheel0.y - node[i].y) == (node[i].r + wheel0.r) * (node[i].r + wheel0.r)) {
						if(wheel0.sign == 1) node[i].sign = -1;
						else node[i].sign = 1;
						node[i].b = wheel0.b * node[i].r;
						node[i].a = wheel0.a * wheel0.r;
						LL Gcd = gcd(node[i].a, node[i].b);
						node[i].b /= Gcd;
						node[i].a /= Gcd;
						que.push(node[i]);
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			if(node[i].sign == 0) puts("not moving");
			else {
				if(node[i].b == 1) printf("%lld", node[i].a);
				else printf("%lld/%lld", node[i].a, node[i].b);
				if(node[i].sign == 1) puts(" clockwise");
				else puts(" counterclockwise");
			}
		}
	}
	return 0;
}
