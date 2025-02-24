// P3709.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 200005;
struct Elem {
	int val;
	int index;
	bool operator < (const Elem& e) const {
		return val < e.val;
	}
} elem[maxn];
int n, m;
int a[maxn];
struct Node {
	int l, r;
	int block;
	int order;
	bool operator < (const Node& e) const {
		if (block == e.block) return r < e.r;
		else return block < e.block;
	}
} node[maxn];
int cnt[maxn];
int num[maxn];
int res;

void Inc(int pos) {
	cnt[num[a[pos]]]--;
	if (res == num[a[pos]]) res++;
	num[a[pos]]++;
	cnt[num[a[pos]]]++;
}

void Dec(int pos) {
	cnt[num[a[pos]]]--;
	if (res == num[a[pos]] && cnt[num[a[pos]]] == 0) res--;
	num[a[pos]]--;
	cnt[num[a[pos]]]++;
}
int ans[maxn];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			cin >> elem[i].val;
			elem[i].index = i;
		}
		sort(elem + 1, elem + 1 + n);
		for (int i = 1, j = 0; i <= n; ++i) {
			if (i == 1 || elem[i].val != elem[i - 1].val) j++;
			a[elem[i].index] = j;
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
		memset(cnt, 0, sizeof(cnt));
		memset(num, 0, sizeof(num));
		res = 0;
		for (int i = 1; i <= m; ++i) {
			while (ql > node[i].l) Inc(--ql);
			while (qr < node[i].r) Inc(++qr);
			while (ql < node[i].l) Dec(ql++);
			while (qr > node[i].r) Dec(qr--);
			ans[node[i].order] = res;
		}
		for (int i = 1; i <= m; ++i) {
			cout << -ans[i] << '\n';
		}
	}
    return 0;
}

