// P2709.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 50005;
int n, m, k;
int a[maxn];
LL res;
int num[maxn];
struct Node {
	int block;
	int l, r;
	int order;
	bool operator < (const Node& e) const {
		if (block == e.block) return r < e.r;
		else return block < e.block;
	}
} node[maxn];
LL ans[maxn];

void Inc(int pos) {
	res -= (LL)num[a[pos]] * num[a[pos]];
	num[a[pos]]++;
	res += (LL)num[a[pos]] * num[a[pos]];
}

void Dec(int pos) {
	res -= (LL)num[a[pos]] * num[a[pos]];
	num[a[pos]]--;
	res += (LL)num[a[pos]] * num[a[pos]];
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> k) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		int Magic = sqrt(n);
		for (int i = 1; i <= m; ++i) {
			cin >> node[i].l >> node[i].r;
			node[i].block = node[i].l / Magic;
			node[i].order = i;
		}
		sort(node + 1, node + 1 + m);
		int ql = node[1].l;
		int qr = node[1].l - 1;
		res = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= m; ++i) {
			while (ql > node[i].l) Inc(--ql);
			while (qr < node[i].r) Inc(++qr);
			while (ql < node[i].l) Dec(ql++);
			while (qr > node[i].r) Dec(qr--);
			ans[node[i].order] = res;
		}
		for (int i = 1; i <= m; ++i) {
			cout << ans[i] << '\n';
		}
	}
    return 0;
}

