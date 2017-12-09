#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int main() {
    int p;
    int a[6];
    int b[6];
    int judge[10];
    while(~scanf("%d", &p)) {
        for(int i = 0; i < 6; ++i) scanf("%d", &a[i]);
        for(int i = 0; i < 6; ++i) scanf("%d", &b[i]);
        mem(judge, 0);
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < 6; ++j) {
                int temp = (a[i] + b[j]) % p;
                judge[temp]++;
            }
        }
        bool ok = true;
        for(int i = 1; i < p; ++i) {
            if(judge[i] != judge[i - 1]) {
                ok = false;
                break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
