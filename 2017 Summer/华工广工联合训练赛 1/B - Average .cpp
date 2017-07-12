#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 20000
#define LL long long
#define MOD 1000000007
using namespace std;
LL fact[maxn], inv[maxn], fiv[maxn];

void init()  
{  
    fact[0] = fact[1] = 1;  
    fiv[0] = fiv[1] = 1;   
    inv[1] = 1;  
    for(int i = 2; i < maxn; ++i)    
    {  
        fact[i] = (1LL * fact[i - 1] * i) % MOD;  
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;  
        fiv[i] = (1LL * inv[i] * fiv[i - 1]) % MOD;  
    }  
}  

LL C(LL m, LL k) {
	if(m < k || k < 0) return 0;
	LL sum = (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
	return sum;
}

int n, fullmarks;

int main() {
	init();
//	printf("%d\n", -1%2);
	while(~scanf("%d%d", &n, &fullmarks), n || fullmarks) {
		LL ans = 0;
		for(int i = 0; i <= fullmarks; i++) {
			LL res = 1LL * (n - 1) * i;
			LL temp = 0;
			for(int j = 0; j <= n; j++) {
				LL m = res + n - 1 - j * (fullmarks + 1) - 1;
				LL k = n - 2;
				LL add = (1LL * C(m, k) * C(n - 1, j) % MOD);
				if(j % 2 != 0) add = (MOD - add) % MOD;
				temp = (temp + add) % MOD;
			}
			ans = (ans + temp) % MOD;
		}
		ans = (ans * n) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
} 
