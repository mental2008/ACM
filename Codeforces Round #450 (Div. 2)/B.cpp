#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
bool vis[maxn];
int main() {
    LL a, b;
    int c;
    mem(vis, 0);
    scanf("%lld%lld%d", &a, &b, &c);
    for(int i = 1; i < maxn; ++i) {
        a *= 10;
        int temp = a / b;
        a = a - temp * b;
        if(temp == c) {
            printf("%d\n", i);
            break;
        }
        if(vis[a]) {
            puts("-1");
            break;
        }
        vis[a] = 1;
    }
    return 0;
}
