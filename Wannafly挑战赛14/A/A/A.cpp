// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	while (caseCnt--) {
		ULL k, m;
		cin >> k >> m;
		ULL res = 1;
		if (k % 3 == 0) {
			ULL a = k + 1;
			ULL b = k + 2;
			ULL c = (k + 3) / 3;
			res = (((a * b) / 2 % m) * c) % m;
		}
		else if (k % 3 == 1) {
			ULL a = k + 1;
			ULL b = (k + 2) / 3;
			ULL c = k + 3;
			if ((k + 1) % 2 == 0) a = a / 2;
			else b = b / 2;
			res = (((a * b) % m) * c) % m;
		}
		else {
			ULL a = (k + 1) / 3;
			ULL b = k + 2;
			ULL c = k + 3;
			if ((k + 2) % 2 == 0) b = b / 2;
			else c = c / 2;
			res = (((a * b) % m) * c) % m;
		}
		cout << res << '\n';
	}
    return 0;
}

