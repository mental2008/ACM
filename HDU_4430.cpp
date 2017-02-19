#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
LL n;
LL check(LL x, int i){
	LL sum = 0;
	LL res = 1;
	for(int j = 1; j <= i; j++){
		if(n / res < x){
			sum = n + 1;
			break;
		}
		res *= x;
		sum += res;
		if(sum > n) break;
	}
	return sum - n;
}
int main(){
	while(~scanf("%lld", &n)){
		int ans = 1;
		LL k = n - 1;
		for(int i = 2; i <= 45; i++){
			LL l = 2, r = n;
			while(r >= l){
				LL mid = (l + r) / 2;
				if(check(mid, i) > 0) r = mid - 1;
				else if(check(mid, i) < -1) l = mid + 1;
				else{
					if(i * mid < ans * k){
						ans = i;
						k = mid;
					}
					break;
				}
			}
		}
		printf("%d %lld\n", ans, k);
	}
	return 0;
}
