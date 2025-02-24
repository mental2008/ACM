// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1000005;
int n;
LL x[1005], y[1005];

struct Node {
	LL x, y;
	bool operator < (const Node& e) const {
		if (x == e.x) return y < e.y;
		else return x < e.x;
	}
	bool operator == (const Node& e) const {
		if (x == e.x && y == e.y) return true;
		else return false;
	}
} node[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	while (caseCnt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				node[cnt].x = x[i] + x[j];
				node[cnt].y = y[i] + y[j];
				cnt++;
			}
		}
		sort(node, node + cnt);
		LL ans = 0;
		for (int i = 0; i < cnt; ++i) {
			int sum = 1;
			int j = i;
			while (j < cnt && node[j] == node[j + 1]) {
				sum++;
				j++;
			}
			ans = ans + (sum - 1) * sum / 2;
			i = j;
		}
		cout << ans << '\n';
	}
    return 0;
}

