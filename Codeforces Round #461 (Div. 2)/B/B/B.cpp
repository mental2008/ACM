// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
map<LL, bool> mp;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LL x = 100000000, y = 10000;
	mp.clear();
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int ti = i;
			int tj = j;
			int k = ti ^ tj;
			if (k > n) continue;
			if (k < tj) {
				swap(tj, k);
			}
			if (tj < ti) {
				swap(tj, ti);
			}
			if (ti + tj <= k) continue;
			LL temp = ti * x + tj * y + k;
			if (mp[temp] == 1) {
				;
			}
			else {
				mp[temp] = 1;
				ans++;
			}
		}
	}
	cout << ans << '\n';
    return 0;
}

