#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 50005;
int n;
int phi[maxn];
int main() {
	while(~scanf("%d", &n), n) {
		mem(phi, 0);
		phi[1] = 1;
		for(int i = 2; i <= n; i++) {
			if(!phi[i]) {
				for(int j = i; j <= n; j += i) {
					if(!phi[j]) phi[j] = j;
					phi[j] = phi[j] / i * (i - 1);
				}
			}
 		}
 		int ans = 0;
 		for(int i = 2; i <= n; i++) {
 			ans += phi[i];
		}
		printf("%d\n", 2 * ans + 1);
	}
	return 0;
} 
