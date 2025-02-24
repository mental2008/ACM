// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		int state = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];	
		}
		if (n > 1) {
			state = a[n - 1] - a[n - 2];
		}
		else {
			state = 0;
		}
		if (a[n - 1] == 0) cout << "UP\n";
		else if (a[n - 1] == 15) cout << "DOWN\n";
		else if (state == 0) cout << "-1\n";
		else {
			if (state == 1) cout << "UP\n";
			else cout << "DOWN\n";
		}
	}
    return 0;
}

