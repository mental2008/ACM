// BZOJ_2038.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 50050;
int n, m;
typedef long long LL;

struct Node {
	int block;
	int l, r;
	int order;
	bool operator < (const Node& e) const {
		if (block == e.block) return r < e.r;
		else return block < e.block;
	}
} node[maxn];

LL gcd(LL x, LL y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int color[maxn];
LL sum[maxn];
int num[maxn];
LL ans[maxn];

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &color[i]);
		}
		int Magic = sqrt(n);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &node[i].l, &node[i].r);
			node[i].order = i;
			node[i].block = node[i].l / Magic;
			sum[i] = (LL)(node[i].r - node[i].l + 1) * (node[i].r - node[i].l) / 2LL;
		}
		memset(num, 0, sizeof(num));
		sort(node + 1, node + 1 + m);
		int ql = node[1].l;
		int qr = node[1].l - 1;
		LL res = 0;
		for (int i = 1; i <= m; ++i) {
			while (ql > node[i].l) {
				ql--;
				res += num[color[ql]];
				num[color[ql]]++;
			}
			while (qr < node[i].r) {
				qr++;
				res += num[color[qr]];
				num[color[qr]]++;
			}
			while (ql < node[i].l) {
				num[color[ql]]--;
				res -= num[color[ql]];
				ql++;
			}
			while (qr > node[i].r) {
				num[color[qr]]--;
				res -= num[color[qr]];
				qr--;
			}
			ans[node[i].order] = res;
		}
		for (int i = 1; i <= m; ++i) {
			LL Gcd = gcd(ans[i], sum[i]);
			printf("%lld/%lld\n", (ans[i] / Gcd), (sum[i] / Gcd));
		}
	}
    return 0;
}

