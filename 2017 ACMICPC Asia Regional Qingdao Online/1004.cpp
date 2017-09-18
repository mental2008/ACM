#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);

LL gcd(LL x, LL y) {
    return (y == 0 ? x : gcd(y, x % y));
}

void solve(double f, LL md, LL *num, LL *denom)
{
	LL a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
	LL x, d, n = 1;
	int i, neg = 0;

	if (md <= 1) { *denom = 1; *num = (LL) f; return; }

	while (f != floor(f)) { n <<= 1; f *= 2; }
	d = f;

	for (i = 0; i < 128; i++) {
		a = n ? d / n : 0;
		if (i && !a) break;

		x = d; d = n; n = x % n;

		x = a;
		if (k[1] * a + k[0] >= md) {
			x = (md - k[0]) / k[1];
			if (x * 2 >= a || k[1] >= md)
				i = 129;
			else
				break;
		}

		h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
		k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
        LL Gcd = gcd(h[1], k[1]);
        h[1] /= Gcd, k[1] /= Gcd;
	}
	*denom = k[1];
    // printf("%lld\n", k[1]);
	*num = neg ? -h[1] : h[1];
}

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int k;
        scanf("%d", &k);
        double temp = pow(k, 2.0 / 3);
        LL num, denom;
        solve(temp, 100000, &num, &denom);
        printf("%lld/%lld\n", num, denom);
    }
	return 0;
}
