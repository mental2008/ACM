// P1903.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10005;
int n, m;
int color[maxn];
int sz, cnt;

struct Node {
	int block;
	int id;
	int l, r;
	int change;
	bool operator < (const Node& e) const {
		if (block == e.block) return r < e.r;
		else return block < e.block;
	}
} node[maxn];
int las[maxn];

struct Modify {
	int pos;
	int col;
	int pre;
} modi[maxn];
int ans[maxn];
int num[1000005];
bool vis[maxn];
int res;

void cal(int pos) {
	if (vis[pos]) {
		if ((--num[color[pos]]) == 0) res--;
	}
	else {
		if ((++num[color[pos]]) == 1) res++;
	}
	vis[pos] = !vis[pos];
}

void change(int pos, int col) {
	if (vis[pos]) {
		cal(pos);
		color[pos] = col;
		cal(pos);
	}
	else color[pos] = col;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			cin >> color[i];
			las[i] = color[i];
		}
		int Magic = sqrt(n);
		sz = cnt = 0;
		for (int i = 1; i <= m; ++i) {
			char order;
			cin >> order;
			if (order == 'Q') {
				int l, r;
				cin >> l >> r;
				++sz;
				node[sz].l = l;
				node[sz].r = r;
				node[sz].id = sz;
				node[sz].block = l / Magic;
				node[sz].change = cnt;
			}
			else {
				int P, Col;
				cin >> P >> Col;
				++cnt;
				modi[cnt].pos = P;
				modi[cnt].col = Col;
				modi[cnt].pre = las[P];
				las[P] = Col;
			}
		}
		sort(node + 1, node + 1 + sz);
		memset(num, 0, sizeof(num));
		memset(vis, 0, sizeof(vis));
		int ql = node[1].l;
		int qr = node[1].l - 1;
		res = 0;
		node[0].change = 0;
		for (int i = 1; i <= sz; ++i) {
			for (int j = node[i - 1].change + 1; j <= node[i].change; ++j) {
				change(modi[j].pos, modi[j].col);
			}
			for (int j = node[i - 1].change; j >= node[i].change + 1; --j) {
				change(modi[j].pos, modi[j].pre);
			}
			while (ql > node[i].l) cal(--ql);
			while (qr < node[i].r) cal(++qr);
			while (ql < node[i].l) cal(ql++);
			while (qr > node[i].r) cal(qr--);
			ans[node[i].id] = res;
		}
		for (int i = 1; i <= sz; ++i) {
			cout << ans[i] << '\n';
		}
	}
    return 0;
}

