#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int main() {
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    int ans;
    if(a <= b && a <= c) {
        ans = (n - 1) * a;
    }
    else if(b <= a && b <= c) {
        ans = (n - 1) * b;
    }
    else {
        if(n == 1) ans = 0;
        else ans = min(a, b) + (n - 2) * c;
    }
    printf("%d\n", ans);
    return 0;
}
