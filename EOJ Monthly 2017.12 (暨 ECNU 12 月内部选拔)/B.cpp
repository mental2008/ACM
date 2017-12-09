#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

ULL solve(ULL n) {
    return n * (n - 1) / 2;
}

int main() {
    ULL n, m;
    while(~scanf("%llu%llu", &n, &m)) {
        ULL ans = 0;
        if(n > m) swap(n, m);
        if(n == 1) ans = 0;
        else if(n == 2) {
            ans = solve(m / 2) * 2 + solve((m + 1) / 2) * 2;
        }
        else {
            if(n == 3 && m == 3) ans = solve(8);
            else ans = solve(n * m);
        }
        cout << ans << '\n';
    }
    return 0;
}
