// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	while (cin >> n >> k) {
		string s;
		cin >> s;
		int pos = 0;
		if (n == 1) cout << s << '\n';
		else {
			while (true) {
				if (k == 0) break;
				bool ok = false;
				while (pos < n - 1) {
					if (pos + 2 < n) {
						if (pos % 2 == 0 && s[pos] == '4' && s[pos + 1] == '7' && s[pos + 2] == '7') {
							if (k % 2 == 1) {
								s[pos + 1] = '4';
							}
							ok = false;
							break;
						}
					}
					if (s[pos] == '4' && s[pos + 1] == '7') {
						ok = true;
						if (pos % 2 == 0) {
							s[pos + 1] = '4';
							pos++;
						}
						else {
							s[pos] = '7';
							pos--;
						}
						break;
					}
					pos++;
				}
				if (!ok) break;
				k--;
			}
			cout << s << '\n';
		}
	}
    return 0;
}

