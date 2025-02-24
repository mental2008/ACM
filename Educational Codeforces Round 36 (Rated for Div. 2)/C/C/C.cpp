// C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int cnt[15];

int main()
{
	ios::sync_with_stdio(false);
	string a, b;
	while (cin >> a >> b) {
		int len1 = a.size();
		int len2 = b.size();
		mem(cnt, 0);
		/*if (len1 < len2) {
			for (int i = 1; i <= len2 - len1; ++i) cnt[0]++;
		}*/
		for (int i = 0; i < len1; ++i) {
			cnt[a[i] - '0']++;
		}
		LL ans = 0;
		if (len2 > len1) {
			for (int i = 9; i >= 0; --i) {
				for (int j = 1; j <= cnt[i]; ++j) {
					ans = ans * 10 + i;
				}
			}
		}
		else {
			bool sign = false;
			for (int i = 0; i < len2; ++i) {
				if (sign) {
					for (int j = 9; j >= 0; --j) {
						if (cnt[j]) {
							ans = ans * 10 + j;
							cnt[j]--;
							break;
						}
					}
					continue;
				}
				bool ok = false;
				if (cnt[b[i] - '0'] >= 1) {
					LL res = 0;
					for (int j = i + 1; j < len2; ++j) {
						res = res * 10 + (b[j] - '0');
					}
					LL temp = 0;
					cnt[b[i] - '0']--;
					for (int j = 0; j < 10; ++j) {
						for (int k = 0; k < cnt[j]; ++k) {
							temp = temp * 10 + j;
						}
					}
					if (res >= temp) {
						ok = true;
						ans = ans * 10 + b[i] - '0';
					}
					else cnt[b[i] - '0']++;
				}
				if (!ok) {
					sign = true;
					for (int j = b[i] - '0' - 1; j >= 0; --j) {
						if (cnt[j]) {
							ans = ans * 10 + j;
							cnt[j]--;
							break;
						}
					}
				}
			}
		}
		
		cout << ans << '\n';
	}
    return 0;
}

