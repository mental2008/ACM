// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
vector<LL> vec;

void dfs(int limit, int depth, LL res) {
	if (limit == depth) {
		vec.push_back(res);
		return;
	}
	dfs(limit, depth + 1, res * 10 + 4);
	dfs(limit, depth + 1, res * 10 + 7);
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 9; ++i) {
		dfs(i, 0, 0);
	}
	vec.push_back(4444444444LL);
	int len = vec.size();
	LL l, r;
	while (cin >> l >> r) {
		LL ans = 0;
		for (int i = 0; i < len; ++i) {
			if (vec[i] >= r) {
				if (i == 0) ans += (r - l + 1) * vec[i];
				else ans += (r - max(vec[i - 1], l - 1)) * vec[i];
				break;
			}
			if (vec[i] >= l) {
				if (i == 0) ans += (vec[i] - l + 1) * vec[i];
				else ans += min(vec[i] - l + 1, vec[i] - vec[i - 1]) * vec[i];
			}
		}
		cout << ans << '\n';
	}
    return 0;
}

