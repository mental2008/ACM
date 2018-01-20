// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int year, month, day;
	int hour, minute, second;
	while (~scanf("%d-%d-%d", &year, &month, &day)) {
		scanf("%d:%d:%d", &hour, &minute, &second);
		int t;
		scanf("%d", &t);
		int res = hour * 60 * 60 + minute * 60 + second;
		int sum = 24 * 60 * 60;
		if (res + t < sum) puts("0");
		else {
			int ans = 1;
			t -= (sum - res);
			ans += (t / sum);
			printf("%d\n", ans);
		}
	}
    return 0;
}

