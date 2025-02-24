// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] < 0) {
			cout << a[i] << '\n';
			return 0;
		}
		if (a[i] == 0) continue;
		else {
			int temp = sqrt(a[i]);
			if (temp * temp == a[i]) {
				continue;
			}
			cout << a[i] << '\n';
			return 0;
		}
	}
    return 0;
}

