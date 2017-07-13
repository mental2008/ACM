#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
int main() {
	int n;
	while(~scanf("%d", &n)) {
		LL upper = 0;
		for(int i = 1; i <= 6; i++) {
			upper += (1LL * i * pow(26, i));
			if(n < upper) {
				LL lower = upper - 1LL * i * pow(26, i);
				LL x = n - lower;
//				int axis[10];
//				memset(axis, 0, sizeof(axis));
//				
				printf("%c\n", (x + 'A'));
				
				break;
			}
		}
	}
	return 0;
}
