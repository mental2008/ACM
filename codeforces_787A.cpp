#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

void extendGcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return;
	}
	else {
		extendGcd(b, a % b, x, y);
		int tmp = x;
		x = y;
		y = tmp - a / b * y;
		return;
	}
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = a;
	int B = c;
	int C = (d - b);
	if(C < 0) C += B;
	int Gcd = gcd(A, B);
	if(C % Gcd != 0) {
		cout << -1 << endl;
	}
	else {
		int x, y;
		A /= Gcd;
		B /= Gcd;
		C /= Gcd;
		extendGcd(A, B, x, y);
		x = (x * C) % B;
		while(x < 0 || (b + a * x - d) / c < 0) {
			x += B;
		}
		cout << b + a * x << endl;
	}
	return 0;
}
