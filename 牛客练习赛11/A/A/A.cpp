// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int a[maxn];
int temp[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		while (m--) {
			int order;
			cin >> order;
			if (order == 1) {
				int l, r, x, y;
				cin >> l >> r >> x >> y;
				for (int i = l; i <= r; ++i) {
					if (a[i] == x) {
						a[i] = y;
					}
				}
			}
			else {
				int l, r, k;
				cin >> l >> r >> k;
				for (int i = l; i <= r; ++i) {
					temp[i - l] = a[i];
				}
				sort(temp, temp + r - l + 1);
				cout << temp[k - 1] << '\n';
			}
		}
	}
    return 0;
}

