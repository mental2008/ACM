// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 5005;
int n, m;
double a, b;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		double res = 0x3f3f3f3f;
		for (int i = 1; i <= n; ++i) {
			cin >> a >> b;
			res = min(res, a / b);
		}
		cout << fixed << setprecision(6) << (res * m) << '\n';
	}
    return 0;
}

