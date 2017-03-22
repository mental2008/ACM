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
	}
}

int main() {
	LL s1, s2, v1, v2, m;
	cin >> s1 >> s2 >> v1 >> v2 >> m;
	LL t, k;
	LL A = v1 - v2;
	LL B = m;
	LL C = s2 - s1;
	if(A < 0) A += m;
	LL Gcd = gcd(A, B);
	if(C % Gcd != 0) {
		cout << -1 << endl;
		return 0;
	}
	A /= Gcd;
	B /= Gcd;
	C /= Gcd;
	extendGcd(A, B, t, k);
	t = (t * C) % B;
	while(t < 0) t += B;
	t %= B;
	cout << t << endl;
	return 0;
}
