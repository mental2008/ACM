// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
const int maxn = 100005;
LL fact[maxn], inv[maxn], fiv[maxn];

void init() {
	fact[0] = fact[1] = 1;
	fiv[0] = fiv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < maxn; ++i)
	{
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
		fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;
	}
}

LL C(LL m, LL k) {
	if (m < k || k < 0) return 0;
	LL sum = (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
	return sum;
}

LL quick_pow(LL x, LL n) {
	LL res = 1;
	LL p = x;
	while (n) {
		if (n & 1) res = (res * p) % MOD;
		p = (p * p) % MOD;
		n >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	init();
	while (caseCnt--) {
		LL a, b, n, m;
		cin >> a >> b >> n >> m;
		LL ans = (C(n - 1, m - 1) * quick_pow(b, m - 1) % MOD) * quick_pow(a, n - m) % MOD;
		cout << ans << '\n';
	}
    return 0;
}

