#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for(int i = 1; i <= n; ++i) {
        LL val;
        scanf("%lld", &val);
        sum += val;
    }
    LL a = -1, b = -1;
    for(int i = 1; i <= n; ++i) {
        LL val;
        scanf("%lld", &val);
        if(val >= a) {
            b = a;
            a = val;
        }
        else if(val > b) b = val;
    }
    if(a + b >= sum) puts("YES");
    else puts("NO");
    return 0;
}
