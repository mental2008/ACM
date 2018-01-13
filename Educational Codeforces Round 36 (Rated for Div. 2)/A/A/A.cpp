// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, k;

int main()
{
	while (~scanf("%d%d", &n, &k)) {
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; ++i) {
			int val;
			scanf("%d", &val);
			if (k % val == 0) {
				ans = min(k / val, ans);
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}

