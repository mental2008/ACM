#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
LL b[35];
int main() {
    mem(b, 0);
    b[0] = 0;
    for(int i = 1; i <= 30; ++i) {
        b[i] = 2LL * b[i - 1] + 2;
    }
    int k;
    while(~scanf("%d", &k)) {
        printf("%lld\n", b[k] + 1);
    }
    return 0;
}
