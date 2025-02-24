// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int res = 0;
	for (int k = 1; k <= n / 2; ++k) {
		for (int i = 0; i < n; ++i) {
			if (i + 2 * k > n) continue;
			string a = s.substr(i, k);
			string b = s.substr(i + k, k);
			if (a == b) {
				res = max(res, k);
			}
		}
	}
	int ans;
	if (res == 0) ans = n;
	else ans = n - res + 1;
	cout << ans << '\n';
    return 0;
}

