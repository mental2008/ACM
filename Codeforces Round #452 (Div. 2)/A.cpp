#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-6;
const int maxn = 2e5 + 5;
int n;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        int one = 0;
        int two = 0;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d", &val);
            if(val == 1) one++;
            else two++;
        }
        while(one >= 1 && two >= 1) {
            one--;
            two--;
            ans++;
        }
        while(one >= 3) {
            one -= 3;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
