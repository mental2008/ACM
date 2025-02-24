// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;
LL n, k;

string solve() {
	for (int i = 1; i <= k; ++i) {
		if (n % i != i - 1) {
			return "No";
		}
	}
	return "Yes";
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cout << solve() << '\n';
    return 0;
}

