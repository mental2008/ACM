// HDU_1496.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2e6 + 5;
int Hash[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if ((a < 0 && b < 0 && c < 0 && d < 0) || (a > 0 && b > 0 && c > 0 && d > 0)) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		memset(Hash, 0, sizeof(Hash));
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				Hash[a * i * i + b * j * j + 1000000]++;
			}
		}
		for (int i = 1; i <= 100; ++i) {
			for (int j = 1; j <= 100; ++j) {
				ans += Hash[-c * i * i - d * j * j + 1000000];
			}
		}
		cout << ans * 16 << '\n';
	}
    return 0;
}

