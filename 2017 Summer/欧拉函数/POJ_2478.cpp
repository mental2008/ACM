#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 1e6 + 5;
typedef long long LL;
int phi[maxn];
LL sum[maxn];
int main() {
    phi[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(!phi[i]) {
            for(int j = i; j < maxn; j += i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    sum[1] = 0;
    for(int i = 2; i < maxn; ++i) {
        sum[i] = sum[i - 1] + phi[i];
    }
    int n;
    while(~scanf("%d", &n), n) {
        printf("%lld\n", sum[n]);
    }
    return 0;
}
