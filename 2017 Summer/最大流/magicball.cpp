#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n;
int main() {
	while(~scanf("%d", &n)) {
		int ans = 0;
		memset(a, 0, sizeof(a));
		while(1) {
			ans++;
			bool ok = false;
			for(int i = 1; i <= n; i++) {
				if(!a[i]) continue;
				if((int)sqrt(a[i] + ans) * (int)sqrt(a[i] + ans) == (a[i] + ans)) {
					//printf("%d %d\n", a[i], ans);
					a[i] = ans;
					ok = true;
					break;
				}
			}
			if(!ok) {
				for(int i = 1; i <= n; i++) {
					if(a[i] == 0) {
						a[i] = ans;
						ok = true;
						break;
					}
				}
			}
			if(!ok) {
				printf("%d\n", ans - 1);
				break;
			}
		}
	}
	return 0;
}
