// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int bit[maxn];
LL n;
int k;

bool solve(LL limit) {
	if (limit < 0) {
		LL need = (1LL << (-limit));
		if (need > k || n > k) return 0;
		if (need * n > k) return 0;
		int index = 0;
		for (int i = 1; i <= need * n; ++i) {
			bit[i] = limit;
		}
		for (int i = need * n + 1; i <= k; ++i) {
			bit[i - 1]--;
			bit[i] = bit[i - 1];
		}
		return 1;
	}
	else {
		LL upper = (1LL << limit);
		if (upper > n) return 0;
		LL res = n;
		int index;
		for (index = 1; index <= k; ++index) {
			for (int j = limit; j >= 0; --j) {
				if (res >= (1LL << j)) {
					bit[index] = j;
					res -= (1LL << j);
					break;
				}
			}
			if (res == 0) break;
		}
		if (res != 0) return 0;
		for (int i = index + 1; i <= k; ++i) {
			bit[i - 1]--;
			bit[i] = bit[i - 1];
		}
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	bool ok = false;
	for (int i = -62; i <= 62; ++i) {
		if (solve(i)) {
			ok = true;
			break;
		}
	}
	if (!ok) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for (int i = 1; i <= k; ++i) {
		cout << bit[i];
		if (i == k) cout << '\n';
		else cout << ' ';
	}
	return 0;
}