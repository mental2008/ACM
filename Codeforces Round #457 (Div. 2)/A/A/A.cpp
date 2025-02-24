// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int x;
	int hh, mm;
	while (cin >> x >> hh >> mm) {
		int ans = 0;
		while (1) {
			if (hh % 10 == 7 || (hh / 10 == 7) || mm % 10 == 7 || (mm / 10 == 7)) {
				break;
			}
			if (mm >= x) {
				mm -= x;
			}
			else {
				if (hh == 0) {
					hh = 24;
				}
				hh--;
				mm = mm + 60 - x;
			}
			ans++;
		}
		cout << ans << '\n';
	}
    return 0;
}

