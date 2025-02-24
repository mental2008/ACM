// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LL x = 1000000000;
	LL y = -1;
	LL pos = -1;
	bool ok = true;
	LL MaxVal = -1;
	for (int i = 0; i < n; ++i) {
		LL val;
		cin >> val;
		if (pos == -1) pos = val;
		else {
			if (pos == val) {
				ok = false;
				continue;
			}
			if (val == pos - 1 || val == pos + 1);
			else {
				LL temp = abs(pos - val);
				if (y == -1) y = temp;
				else if (y != temp) ok = false;
			}
			pos = val;
		}
		MaxVal = max(MaxVal, val);
	}
	if (y == -1) {
		y = MaxVal;
		x = 1;
	}
	if (ok) {
		cout << "YES\n";
		cout << x << " " << y << '\n';
	}
	else cout << "NO\n";
    return 0;
}

