// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 2005;
char ch[maxn][maxn];
int n, m, k;
typedef long long LL;
LL ans;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> k) {
		for (int i = 0; i < n; ++i) {
			cin >> ch[i];
		}
		ans = 0;
		if (k == 1) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (ch[i][j] == '.') ans++;
				}
			}
			cout << ans << '\n';
			continue;
		}
		for (int i = 0; i < n; ++i) {
			int cons = 0;
			for (int j = 0; j < m; ++j) {
				if (ch[i][j] == '.') {
					cons++;
				}
				else {
					if (cons >= k) {
						ans += (LL)(cons - k + 1);
					}
					cons = 0;
				}
			}
			if (cons >= k) {
				ans += (LL)(cons - k + 1);
			}
		}
		for (int j = 0; j < m; ++j) {
			int cons = 0;
			for (int i = 0; i < n; ++i) {
				if (ch[i][j] == '.') {
					cons++;
				}
				else {
					if (cons >= k) {
						ans += (LL)(cons - k + 1);
					}
					cons = 0;
				}
			}
			if (cons >= k) {
				ans += (LL)(cons - k + 1);
			}
		}
		cout << ans << '\n';
	}
    return 0;
}

