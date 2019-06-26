#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    LL n, q;
    scanf("%lld%lld", &n, &q);
    while(q--) {
        LL x;
        scanf("%lld", &x);
        while(x % 2 == 0) {
            x += (n - (x / 2));
        }
        printf("%lld\n", (x + 1) / 2);
    }
    return 0;
}
