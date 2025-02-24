// D.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn = 105;
double pre[maxn];

double quick_pow(double x, int n) {
	double res = 1;
	double p = x;
	while (n) {
		if (n & 1) res *= p;
		p *= p;
		n >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, l, r;
	int m, L, R;
	pre[1] = 1;
	for (int i = 2; i < maxn; ++i) {
		pre[i] = pre[i - 1] + 1.0 / i;
	}
	while (cin >> n >> l >> r >> m >> L >> R) {
		if (r <= L || n == 0) {
			cout << fixed << setprecision(5) << 0.0 << '\n';
			continue;
		}
		if (R <= l || m == 0) {
			cout << fixed << setprecision(5) << 1.0 << '\n';
			continue;
		}
		double win;
		if (l - L < 1) win = 1.0 / (r - l + 1) * pre[r - l];
		else win = 1.0 / (r - l + 1) * (pre[r - l] - pre[l - L]);
		double lose;
		if (R - r < 1) lose = 1.0 / (r - l + 1) * pre[R - l];
		else lose = 1.0 / (r - l + 1) * (pre[R - l] - pre[R - r]);
		double la = quick_pow(win, m);
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				la *= (i + m - 1);
				la /= (i);
			}
			double res = la * quick_pow(lose, i);
			ans += res;
		}
		int tl = max(L, l), tr = min(R, r);
		if (tr >= tl) {
			double temp = (double)(tr - tl + 1) / (r - l + 1) / (R - L + 1);
			ans *= 1.0 / (1 - temp);
		}
		cout << fixed << setprecision(5) << ans << '\n';
	}
    return 0;
}

