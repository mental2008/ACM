#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        ll x;
        scanf("%lld", &x);
        ll ans = 0;
        for(ll l = 1, r; l <= x; l = r + 1) {
            r = x / (x / l);
            ans += (r - l + 1) * (x / l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
