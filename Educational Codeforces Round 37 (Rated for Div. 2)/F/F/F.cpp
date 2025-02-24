// F.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <time.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
const int maxm = 3e5 + 5;
LL D[maxn];
LL a[maxm];
int n, m;
struct Node {
	LL val;
	bool change;
} node[3 * maxn];

void build(int root, int l, int r) {
	if (l == r) {
		node[root].val = a[l];
		if (a[l] == 1 || a[l] == 2) node[root].change = false;
		else node[root].change = true;
		return;
	}
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	node[root].val = node[root * 2].val + node[root * 2 + 1].val;
	if (node[root * 2].change == false && node[root * 2 + 1].change == false) {
		node[root].change = false;
	}
	else node[root].change = true;
}

void update(int root, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return;
	if (node[root].change == false) return;
	if (l == r) {
		node[root].val = D[node[root].val];
		if (node[root].val == 1 || node[root].val == 2) {
			node[root].change = false;				
		}
		return;
	}
	int mid = (l + r) / 2;
	update(root * 2, l, mid, ql, qr);
	update(root * 2 + 1, mid + 1, r, ql, qr);
	if (node[root * 2].change == false && node[root * 2 + 1].change == false) {
		node[root].change = false;
	}
	else node[root].change = true;
	node[root].val = node[root * 2].val + node[root * 2 + 1].val;
}

LL query(int root, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return node[root].val;
	int mid = (l + r) / 2;
	LL res = query(root * 2, l, mid, ql, qr) + query(root * 2 + 1, mid + 1, r, ql, qr);
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	memset(D, 0, sizeof(D));
	for (int i = 1; i < maxn; ++i) {
		for (int j = i; j < maxn; j += i) {
			D[j]++;
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (m--) {
		int order, l, r;
		cin >> order >> l >> r;
		if (order == 1) {
			update(1, 1, n, l, r);
		}
		else {
			LL ans = query(1, 1, n, l, r);
			cout << ans << '\n';
		}
	}
    return 0;
}

