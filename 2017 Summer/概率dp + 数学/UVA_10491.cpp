#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double a, b, c;
int main() {
	while(~scanf("%lf%lf%lf", &a, &b, &c)) {
		double ans = (a * b + b * (b - 1)) / ((a + b) * (a + b - c - 1));
		printf("%.5lf\n", ans);
	}
	return 0;
}
