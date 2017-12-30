#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int k[3];
    while(~scanf("%d%d%d", &k[0], &k[1], &k[2])) {
        sort(k, k + 3);
        bool ok = true;
        mem(a, 0);
        a[0] = a[k[2]] = a[2 * k[2]] = 1;
        bool one = 0, two = 0;
        for(int i = 0; i <= 2 * k[2]; ++i) {
            if(a[i] == 0) {
                if(one == 0) {
                    one = 1;
                    for(int j = i; j <= 2 * k[2]; j += k[0]) {
                        a[j] = 1;
                    }
                }
                else if(two == 0) {
                    two = 1;
                    for(int j = i; j <= 2 * k[2]; j += k[1]) {
                        a[j] = 1;
                    }
                }
                else {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            puts("YES");
        }
        else {
            ok = true;
            mem(a, 0);
            a[0] = a[k[2]] = a[2 * k[2]] = 1;
            one = 0, two = 0;
            for(int i = 0; i <= 2 * k[2]; ++i) {
                if(a[i] == 0) {
                    if(two == 0) {
                        two = 1;
                        for(int j = i; j <= 2 * k[2]; j += k[1]) {
                            a[j] = 1;
                        }
                    }
                    else if(one == 0) {
                        one = 1;
                        for(int j = i; j <= 2 * k[2]; j += k[0]) {
                            a[j] = 1;
                        }
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
