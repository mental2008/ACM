#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;

LL create(int x) {
    int cnt = 0;
    int res[15];
    while(x) {
        res[cnt] = x % 10;
        x /= 10;
        cnt++;
    }
    LL ans = 0;
    for(int i = cnt - 1; i >= 0; --i) {
        ans = ans * 10 + res[i];
    }
    for(int i = 0; i < cnt; ++i) {
        ans = ans * 10 + res[i];
    }
    return ans;
}

int main() {
    int k;
    LL p;
    scanf("%d%lld", &k, &p);
    LL res = 0;
    for(int i = 1; i <= k; ++i) {
        res = (res + create(i)) % p;
    }
    printf("%lld\n", res);
    return 0;
}
