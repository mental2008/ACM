// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000005;
int a[maxn];
bool vis[maxn];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	bool AllOne = true;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vis[a[i]] = 1;
		if (a[i] != 1) AllOne = false;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1) {
			if (!AllOne) ans++;
			continue;
		}
		for (int j = 2 * a[i]; j < maxn; j += a[i]) {
			if (vis[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
    return 0;
}

