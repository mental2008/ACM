#include <bits/stdc++.h>
#define LL long long
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int n, x;
int main() {
    while(~scanf("%d%d", &n, &x)) {
        if(n == 1) printf("YES\n%d\n", x);
        else if(n == 2) {
            if(x == 0) puts("NO");
            else printf("YES\n0 %d\n", x);
        }
        else {
            puts("YES");
            int y = 0;
            for(int i = 1; i <= n - 3; ++i) {
                printf("%d ", i);
                y ^= i;
            }
            int temp1 = (1 << 17);
            int temp2 = (1 << 18);
            if(y == x) printf("%d %d %d\n", temp1, temp2, temp1 ^ temp2);
            else printf("%d %d %d\n", 0, temp1, temp1 ^ y ^ x);
        }
    }
    return 0;
}
