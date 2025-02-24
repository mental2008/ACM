// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
struct Node {
	int index;
	LL ss, hh;
} node[maxn];
int n;
string s[maxn];

bool cmp(Node x, Node y) {
	if (x.ss * y.hh > x.hh * y.ss) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		node[i].index = i;
		node[i].ss = node[i].hh = 0;
		int len = s[i].size();
		for (int j = 0; j < len; ++j) {
			if (s[i][j] == 's') node[i].ss++;
			else node[i].hh++;
		}
	}
	sort(node, node + n, cmp);
	LL ss = 0;
	LL res = 0;
	LL sign = 0;
	for (int i = 0; i < n; ++i) {
		int len = s[node[i].index].size();
		for (int j = 0; j < len; ++j) {
			if (s[node[i].index][j] == 's') sign++;
			else res += sign;
		}
	}
	cout << res << '\n';
    return 0;
}

