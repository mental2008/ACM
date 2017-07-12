#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 3000
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
	LL sum = (((fact[m] * fiv[k]) % MOD) * fiv[m - k]) % MOD;
	return sum;
}

int a[maxn];
int main() {
	int n, m;
	init();
	while(~scanf("%d%d", &n, &m)) {
		for(int i = 1; i <= m; i++) {
			scanf("%d", &a[i]);
		}
		LL ans = 0;
		for(int i = 0; i < n; i++) {
			LL res = 1;
			for(int j = 1; j <= m; j++) {
				res = (res * C(a[j] + n - i - 1, n - i - 1)) % MOD;
			}
			res = (res * C(n, i)) % MOD;
			if(i % 2 == 0) ans = (ans + res) % MOD;
			else ans = (ans - res) % MOD;
		}
		ans = (ans % MOD + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
