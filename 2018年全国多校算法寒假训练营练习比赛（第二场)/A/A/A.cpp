// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 105;
char s[maxn];

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> s) {
		int len = strlen(s);
		while (1) {
			bool ok = false;
			for (int i = 0; i < len; ++i) {
				if (i < len - 1) {
					if (s[i] == 'o' && s[i + 1] == 'o') {
						s[i] = 'O';
						for (int j = i + 1; j < len - 1; ++j) {
							s[j] = s[j + 1];
						}
						len--;
						i -= 2;
						ok = true;
						break;
					}
					else if (s[i] == 'O' && s[i + 1] == 'O') {
						for (int j = i; j < len - 2; ++j) {
							s[j] = s[j + 2];
						}
						len -= 2;
						ok = true;
						break;
					}
				}
			}
			if (!ok) break;
		}
		for (int i = 0; i < len; ++i) cout << s[i];
		cout << '\n';
	}
    return 0;
}

