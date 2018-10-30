// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			ans++;
			continue;
		}
		if ((s[i] == 'R' && s[i + 1] == 'U') || (s[i] == 'U' && s[i + 1] == 'R')) {
			ans++;
			++i;
		}
		else {
			ans++;
		}
	}
	cout << ans << '\n';
    return 0;
}

