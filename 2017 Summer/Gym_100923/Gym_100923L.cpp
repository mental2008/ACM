#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
char ch[100];
int main() {
    freopen("semipal.in", "r", stdin);
    freopen("semipal.out", "w", stdout);
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        LL n, k;
        scanf("%lld%lld", &n, &k);
        k--;
        for(int i = 1; i < n; ++i) {
            if(k % 2) ch[n - i] = 'b';
            else ch[n - i] = 'a';
            k >>= 1;
        }
        ch[n] = ch[1];
        for(int i = 1; i <= n; ++i) {
            printf("%c", ch[i]);
        }
        puts("");
    }
    return 0;
}
