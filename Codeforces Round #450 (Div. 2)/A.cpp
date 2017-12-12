#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > 0) r++;
        else l++;
    }
    if(l <= 1 || r <= 1) puts("Yes");
    else puts("No");
    return 0;
}
