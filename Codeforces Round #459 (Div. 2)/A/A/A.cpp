// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1005;
char a[maxn];
int fib[maxn];

int main()
{
	for (int i = 1; i <= 1000; ++i) {
		a[i] = 'o';
	}
	fib[1] = 1;
	fib[2] = 1;
	a[1] = 'O';
	for (int i = 3; fib[i - 1] <= 1000; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		a[fib[i]] = 'O';
	}
	int n;
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; ++i) cout << a[i];
		cout << '\n';
	}
    return 0;
}

