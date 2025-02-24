// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
bool prime[maxn];

int main()
{
	ios::sync_with_stdio(false);
	memset(prime, 0, sizeof(prime));
	prime[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		if (prime[i] == 0) {
			for (int j = i * 2; j < maxn; j += i) {
				prime[j] = 1;
			}
		}
	}
	int n, m;
	while (cin >> n >> m) {
		int p;
		for (int i = n - 1; i < maxn; ++i) {
			if (prime[i] == 0) {
				p = i;
				break;
			}
		}
		cout << p << ' ' << p << '\n';
		int avg = p / (n - 1);
		int res = p;
		for (int i = 1; i < n; ++i) {
			cout << i << ' ' << i + 1 << ' ';
			if (i == n - 1) cout << res;
			else cout << avg;
			res -= avg;
			cout << '\n';
		}
		int need = m - (n - 1);
		int u = 1, v = 3;
		while (need) {
			if (v > n) {
				u++;
				v = u + 2;
			}
			cout << u << ' ' << v << ' ' << 100000000 << '\n';
			v++;
			need--;
		}
	}
    return 0;
}

