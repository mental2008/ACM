#include <iostream>
#include <cstdio>
using namespace std;

int cal(int x) {
	int res = 0;
	for(int i = 1; i <= x; i++) {
		int tmp = i;
		while(tmp) {
			if(tmp % 2 == 1) {
				break;
			}
			res++;
			tmp >>= 1;
		}
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		int ans = cal(m) - cal(n) - cal(m - n);
		printf("%d\n", ans);
	}
	return 0;
}
