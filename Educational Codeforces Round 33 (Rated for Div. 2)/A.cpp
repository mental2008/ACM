#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int p1 = 1, p2 = 2;
    bool ok = true;
    while(n--) {
        int win;
        scanf("%d", &win);
        if(ok) {
            if(win != p1 && win != p2) {
                ok = false;
                continue;
            }
            if(p1 == win) {
                int temp;
                for(int i = 1; i <= 3; ++i) {
                    if(i == p1 || i == p2) continue;
                    temp = i;
                }
                p2 = temp;
            }
            else {
                int temp;
                for(int i = 1; i <= 3; ++i) {
                    if(i == p2 || i == p1) continue;
                    temp = i;
                }
                p1 = temp;
            }
        }
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
