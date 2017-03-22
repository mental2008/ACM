#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

LL gcd(LL a, LL b) {
	return (b == 0) ? a : gcd(b, a % b);
}

void extendGcd(LL a, LL b, LL &x, LL &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		extendGcd(b, a % b, x, y);
		LL tmp = x;
		x = y;
		y = tmp - a / b * y;
		return;
	}
}

int main() {
	LL x, y, m, n, L;
	while(cin >> x >> y >> m >> n >> L) {
		LL A = m - n;
		LL B = L;
		LL C = y - x;
		if(A < 0) A += L;
		LL Gcd = gcd(A, B);
		if(C % Gcd != 0) {
			cout << "Impossible" << endl;
			break;
		}
		else {
			A /= Gcd;
			B /= Gcd;
			C /= Gcd;
			LL t, k;
			extendGcd(A, B, t, k);
			t = (t * C) % B;
			while(t < 0) t += B;
			t %= B;
			cout << t << endl;
		}
	}
	return 0;
}
