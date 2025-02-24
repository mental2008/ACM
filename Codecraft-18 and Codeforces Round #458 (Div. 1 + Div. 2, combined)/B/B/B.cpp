// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n;
int cnt[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = maxn - 1; i >= 1; --i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] % 2 == 1) {
			cout << "Conan\n";
			return 0;
		}
	}
	cout << "Agasa\n";
    return 0;
}

