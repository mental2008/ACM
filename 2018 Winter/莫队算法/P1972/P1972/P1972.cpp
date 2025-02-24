// P1972.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 50005;
int n, m;
int color[maxn];
struct Node {
	int l, r;
	int block;
	int order;
	bool operator < (const Node& e) const {
		if (block == e.block) return r < e.r;
		else return block < e.block;
	}
} node[200005];
int num[1000005];
int ans[200005];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) {
			cin >> color[i];
		}
		cin >> m;
		int Magic = sqrt(n);
		for (int i = 1; i <= m; ++i) {
			cin >> node[i].l >> node[i].r;
			node[i].order = i;
			node[i].block = node[i].l / Magic;
		}
		sort(node + 1, node + 1 + m);
		int ql = node[1].l;
		int qr = node[1].l - 1;
		int res = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= m; ++i) {
			while (ql > node[i].l) {
				ql--;
				num[color[ql]]++;
				if (num[color[ql]] == 1) res++;
			}
			while (qr < node[i].r) {
				qr++;
				num[color[qr]]++;
				if (num[color[qr]] == 1) res++;
			}
			while (ql < node[i].l) {
				num[color[ql]]--;
				if (num[color[ql]] == 0) res--;
				ql++;
			}
			while (qr > node[i].r) {
				num[color[qr]]--;
				if (num[color[qr]] == 0) res--;
				qr--;
			}
			ans[node[i].order] = res;
		}
		for (int i = 1; i <= m; ++i) {
			cout << ans[i] << '\n';
		}
	}
    return 0;
}

