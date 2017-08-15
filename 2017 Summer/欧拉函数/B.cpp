#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//typedef long long LL;
const int maxn = 65536 + 5;
bool prime[maxn];
vector<int> vec;
int n;
int main() {
	clock_t start, finish;
	double duration;
	start = clock();
	for(int i = 2; i < maxn; i++) prime[i] = 1;
	for(int i = 2; i < maxn; i++) {
		if(prime[i]) {
			vec.push_back(i);
			for(int j = 2 * i; j < maxn; j += i) {
				prime[j] = 0;
			}
		}
	}
	finish = clock();
	//printf("%lf\n", (double)(finish - start) / CLOCKS_PER_SEC);
	//printf("%d\n", (int)vec.size());
	while(~scanf("%d", &n)) {
		n--;
		int temp = n;
		for(int i = 0; i < vec.size(); i++) {
			if(temp < vec[i]) break;
			if(temp % vec[i] == 0) {
				n = n * (1 - 1.0 / vec[i]);
				while(temp % vec[i] == 0) {
					temp /= vec[i];
				}
			}
		}
		//if(temp > 65536) n = n * (1 - 1.0 / temp);
		printf("%d\n", n);
	}
	return 0;
} 
