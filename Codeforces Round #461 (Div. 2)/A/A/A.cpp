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
LL x, y;
int main()
{
	ios::sync_with_stdio(false);
	cin >> x >> y;
	if (y == 0) puts("No");
	else if (y - 1 > x) puts("No");
	else if (y == 1) {
		if (x == 0) puts("Yes");
		else puts("No");
	}
	else {
		LL temp = x - (y - 1);
		if (temp % 2 == 0) puts("Yes");
		else puts("No");
	}
    return 0;
}

