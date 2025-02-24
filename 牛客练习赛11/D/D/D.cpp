// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 105;
int n;
int a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		int small, big;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 1) small = i;
			else if (a[i] == n) big = i;
		}
		if (small == 1 || big == 1 || small == n || big == n) cout << n - 1 << '\n';
		else {
			int ans = max(abs(small - 1), abs(big - 1));
			ans = max(ans, abs(n - small));
			ans = max(ans, abs(n - big));
			cout << ans << '\n';
		}
	}
    return 0;
}

