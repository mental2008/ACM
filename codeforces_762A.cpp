#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;
LL n;
int k;
int main() {
	while(cin >> n >> k) {
		int count = 0;
		bool is_ok = false;
		LL ans = -1;
		for(int i = 1; i < sqrt(n); i++) {
			if(n % i == 0) {
				count++;
				if(count == k) {
					ans = i;
					is_ok = true;
					break;
				}
			}
		}
		if(is_ok == false) {
			bool is_sqrt = false;
			if((int)sqrt(n) * (int)sqrt(n) == n) {
				is_sqrt = true;
				count++;
				if(count == k) {
					is_ok = true;
					ans = sqrt(n);
				}
			}
			if(is_ok == false) {
				for(int i = sqrt(n) - (int)is_sqrt; i >= 1; i--) {
					if(n % i == 0) {
						count++;
						if(count == k) {
							is_ok = true;
							ans = n / i;
							break;
						}
					}
				}
			}
		}	
		cout << ans << endl;
	}
	return 0;
}
