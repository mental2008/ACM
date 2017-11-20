#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
LL n, m;
int k;

LL quick_pow(LL a, LL num) {
    LL res = 1;
    LL p = a % MOD;
    while(num) {
        if(num & 1) res = (res * p) % MOD;
        p = (p * p) % MOD;
        num >>= 1;
    }
    return res;
}

int main() {
    scanf("%lld%lld%d", &n, &m, &k);
    if(k == -1 && (n + m) % 2){
        puts("0");
    }
    else {
        LL temp = ((m - 1) % (MOD - 1)) * ((n - 1) % (MOD - 1)) % (MOD - 1);
        printf("%lld\n", quick_pow(2, temp));
    }
    return 0;
}
