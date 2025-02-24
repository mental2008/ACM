// SGU_275.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 105;
const int MAX_BASE = 64;
LL a[maxn];
LL b[MAX_BASE];

LL solve(int n) {
	mem(b, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = MAX_BASE - 1; j >= 0; --j) {
			if (a[i] >> j & 1) {
				if (b[j]) a[i] ^= b[j];
				else {
					b[j] = a[i];
					for (int k = j - 1; k >= 0; --k) if (b[k] && (b[j] >> k & 1)) b[j] ^= b[k];
					for (int k = j + 1; k < MAX_BASE; ++k) if (b[k] >> j & 1) b[k] ^= b[j];
					break;
				}
			}
		}
	}
	LL res = 0;
	for (int i = 0; i < MAX_BASE; ++i) {
		cout << i << " " << b[i] << '\n';
		res ^= b[i];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LL ans = solve(n);
		cout << ans << '\n';
	}
    return 0;
}

