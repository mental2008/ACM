// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 200005;
int n;
int a[maxn];
bool vis[maxn];
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> s;
	mem(vis, 0);
	int pos = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != i) {
			if (vis[i]) continue;
			pos = max(pos, i);
			while (a[pos] != i) {
				if (s[pos - 1] == '0') {
					cout << "NO\n";
					return 0;
				}
				vis[a[pos]] = 1;
				pos++;
			}
		}
	}
	cout << "YES\n";
    return 0;
}

