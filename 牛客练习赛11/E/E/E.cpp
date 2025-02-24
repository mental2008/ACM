// E.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 100005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n;
struct Node {
	LL x, y;
	bool operator < (const Node& e) const {
		if (x == e.x) return y < e.y;
		else return x < e.x;
	}
} node[maxn], temp[maxn];

LL dis(Node a, Node b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(Node a, Node b)
{
	return a.y < b.y;
}

LL solve(int left, int right)
{
	LL d = INF;
	if (left == right) return d;
	if (left + 1 == right) return dis(node[left], node[right]);
	int mid = (left + right) / 2;
	LL d1 = solve(left, mid);
	LL d2 = solve(mid, right);
	d = min(d1, d2);
	int k = 0;
	LL dd = sqrt(d) + 1;
	for (int i = left; i <= right; i++)
	{
		if (abs(node[mid].x - node[i].x) <= dd)
			temp[k++] = node[i];
	}
	sort(temp, temp + k, cmp);
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k && temp[j].y - temp[i].y < dd; j++)
		{
			LL d3 = dis(temp[i], temp[j]);
			d = min(d, d3);
		}
	}
	return d;
}

int main()
{
	while (~scanf("%d", &n)) {
		LL las = 0;
		for (int i = 0; i < n; ++i) {
			LL val;
			scanf("%lld", &val);
			las = las + val;
			node[i].x = i;
			node[i].y = las;
		}
		sort(node, node + n);
		printf("%lld\n", solve(0, n - 1));
	}
    return 0;
}

