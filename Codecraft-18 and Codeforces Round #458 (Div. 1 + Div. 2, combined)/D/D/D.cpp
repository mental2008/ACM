// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 5e5 + 5;
int n;
LL a[maxn];

LL gcd(LL x, LL y) {
	return (y == 0 ? x : gcd(y, x % y));
}

LL node[maxn * 3];

void build(int root, int l, int r) {
	if (l == r) {
		node[root] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(root * 2, l, mid);
	build(root * 2 + 1, mid + 1, r);
	node[root] = gcd(node[root * 2], node[root * 2 + 1]);
}

int query(int root, int l, int r, int ql, int qr, LL x) {
	if (l > qr || r < ql) return 1;
	if (l == r) {
		if (node[root] % x == 0) return 1;
		else return 0;
	}
	int mid = (l + r) / 2;
	if (l >= ql && r <= qr) {
		if (node[root] % x == 0) return 1;
	}
	int lson = query(root * 2, l, mid, ql, qr, x);
	if (lson == -1) return -1;
	int rson = query(root * 2 + 1, mid + 1, r, ql, qr, x);
	if (rson == -1) return -1;
	else if (lson == 0 && rson == 0) return -1;
	else if (lson == 0 && rson == 2) return -1;
	else if (lson == 2 && rson == 0) return -1;
	if (lson == 1 && rson == 2) return 2;
	else if (lson == 2 && rson == 1) return 2;
	else if (lson == 1 && rson == 1) return 1;
	else if (lson == 2 && rson == 2) return -1;
	else return 2;
}

void update(int root, int l, int r, int index, LL x) {
	if (l > index || r < index) return;
	if (l == r) {
		node[root] = x;
		return;
	}
	int mid = (l + r) / 2;
	update(root * 2, l, mid, index, x);
	update(root * 2 + 1, mid + 1, r, index, x);
	node[root] = gcd(node[root * 2], node[root * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int order;
		cin >> order;
		if (order == 1) {
			int l, r;
			LL x;
			cin >> l >> r >> x;
			int ans = query(1, 1, n, l, r, x);
			if (ans == 1 || ans == 2) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			int index;
			LL x;
			cin >> index >> x;
			update(1, 1, n, index, x);
		}
	}
	return 0;
}