#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
bool prime[maxn];
vector<int> vec;
LL n;
int main() {
	for(int i = 2; i < maxn; i++) prime[i] = 1;
	for(int i = 2; i < maxn; i++) {
		if(prime[i]) {
			vec.push_back(i);
			for(int j = 2 * i; j < maxn; j += i) {
				prime[j] = 0;
			}	
		}
	}
	while(~scanf("%lld", &n), n) {
		LL temp = n;
		for(int i = 0; i < vec.size(); i++) {
			if(temp % vec[i] == 0) {
				n = n * (1 - 1.0 / vec[i]);
				while(temp % vec[i] == 0) {
					temp /= vec[i];
				}
			}
		}
		if(temp > 1e6) n = n * (1 - 1.0 / temp);
		printf("%lld\n", n);
	}
	return 0;
} 
