#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main() {
	LL n, m;
	while(cin >> n >> m) {
		if(n <= m) {
			cout << n << endl;
			break;
		}
		else {
			LL ans = (-1 + sqrt(1 + 8 * (n - m))) / 2;
			if(ans * (1 + ans) / 2 < n - m) ans++;
			/*LL l = 0, r = 1e9+1e9;
			LL ans = r;
			while(l <= r) {
				LL mid = (l + r) / 2;
				if(mid * (mid + 1) / 2 >= n - m) {
					ans = mid;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}*/
			cout << m + ans << endl;
		}
	}
	return 0;
}
