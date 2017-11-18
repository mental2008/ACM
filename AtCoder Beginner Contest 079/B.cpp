#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL lucas[90];

int main() {
    lucas[0] = 2LL;
    lucas[1] = 1LL;
    for(int i = 2; i <= 86; ++i) lucas[i] = lucas[i - 1] + lucas[i - 2];
    int n;
    scanf("%d", &n);
    printf("%lld\n", lucas[n]);
    return 0;
}
