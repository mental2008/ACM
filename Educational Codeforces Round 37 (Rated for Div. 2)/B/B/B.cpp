// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct Node {
	int index;
	int leave;
	int arrive;
	bool exist;
	/*bool operator < (const Node& e) const {
		if (arrive == e.arrive) index < e.index;
		else return arrive < e.arrive;
	}*/
} node[maxn];

bool cmp(Node x, Node y) {
	if (x.arrive == y.arrive) return x.index < y.index;
	return x.arrive < y.arrive;
}

int n;
int ans[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	while (caseCnt--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> node[i].arrive >> node[i].leave;
			node[i].index = i;
			node[i].exist = false;
		}
		sort(node + 1, node + 1 + n, cmp);
		int t = 1;
		while (t <= 5050) {
			bool ok = false;
			for (int i = 1; i <= n; ++i) {
				if (node[i].exist == false) {
					if (t > node[i].leave) {
						node[i].exist = true;
						ans[node[i].index] = 0;
					}
					else if (t >= node[i].arrive) {
						node[i].exist = true;
						ans[node[i].index] = t;
						ok = true;
						break;
					}
				}
			}
			t++;
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i];
			if (i == n) cout << '\n';
			else cout << ' ';
		}
	}
    return 0;
}

