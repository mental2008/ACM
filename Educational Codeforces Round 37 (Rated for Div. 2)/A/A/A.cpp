// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 205;
const int INF = 0x3f3f3f3f;
int a[maxn];
int n, k;

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	while (caseCnt--) {
		cin >> n >> k;
		fill(a + 1, a + 1 + n, INF);
		for (int i = 1; i <= k; ++i) {
			int pos;
			cin >> pos;
			a[pos] = 1;
			for (int j = pos + 1; j <= n; ++j) {
				a[j] = min(a[j], j - pos + 1);
			}
			for (int j = pos - 1; j >= 1; --j) {
				a[j] = min(a[j], pos - j + 1);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, a[i]);
		}
		cout << ans << '\n';
	}
    return 0;
}

