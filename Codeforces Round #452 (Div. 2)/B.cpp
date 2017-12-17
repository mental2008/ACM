#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-6;
const int maxn = 1e5 + 5;
int month[60] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
int a[30];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        bool status = false;
        for(int i = 0; i + n - 1 < 60; ++i) {
            bool ok = true;
            for(int j = 1; j <= n; ++j) {
                if(month[i + j - 1] != a[j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                status = true;
                break;
            }
        }
        if(status) puts("YES");
        else puts("NO");
    }
    return 0;
}
