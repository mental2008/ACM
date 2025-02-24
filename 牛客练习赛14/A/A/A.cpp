// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 105;
vector<int> prime;
bool vis[maxn];
LL ans = 0;
LL n;

void dfs(int depth, LL res, LL temp, int limit) {
	if (depth > 18) return;
	ans = max(ans, res);
	LL val = temp;
	for (int i = 1; i <= limit; ++i) {
		if (val > n / prime[depth]) break;
		val = val * prime[depth];
		if (val > n) break;
		dfs(depth + 1, res * (i + 1), val, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < maxn; ++i) {
		if (vis[i] == 0) {
			prime.push_back(i);
			for (int j = 2 * i; j < maxn; j += i) {
				vis[j] = 1;
			}
		}
	}
	while (caseCnt--) {
		cin >> n;
		ans = 0;
		dfs(0, 1, 1, 60);
		cout << ans << '\n';
	}
	return 0;
}


