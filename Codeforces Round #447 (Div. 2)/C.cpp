#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
int a[maxn];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	bool ok = true;
	for(int i = 2; i <= n; ++i) {
		if(a[i] % a[1]) {
			ok = false;
			break;
		}
	}
	if(ok) {
		printf("%d\n", 2 * n);
		for(int i = 1; i <= n; ++i) {
			printf("%d %d%c", a[1], a[i], (i == n ? '\n' : ' '));
		}
	}
	else puts("-1");
	return 0;
}
