// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector<int> vec;

void dfs(int depth, int limit, int res, int num, bool first) {
	if (depth == limit) {
		if (res == 10) {
			vec.push_back(num);
		}
		return;
	}
	if (first) {
		for (int i = 1; i <= min(10 - res, 9); ++i) {
			dfs(depth + 1, limit, res + i, num * 10 + i, 0);
		}
	}
	else {
		for (int i = 0; i <= min(10 - res, 9); ++i) {
			dfs(depth + 1, limit, res + i, num * 10 + i, 0);
		}
	}
}

int main()
{
	vec.clear();
	for (int i = 2; i <= 8; ++i) {
		dfs(0, i, 0, 0, 1);
	}
	sort(vec.begin(), vec.end());
	int n;
	while (cin >> n) {
		cout << vec[n - 1] << '\n';
	}
    return 0;
}

