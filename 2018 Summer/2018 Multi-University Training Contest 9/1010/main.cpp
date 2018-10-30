#include <bits/stdc++.h>
using namespace std;

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int a[4], b[4];
        memset(a, 0x3f, sizeof(a));
        memset(b, 0x3f, sizeof(b));
        for(int i = 0; i < x; ++i) scanf("%d", &a[i]);
        for(int i = 0; i < y; ++i) scanf("%d", &b[i]);
        a[0] += 2;
        b[0] += 2;
        a[1]++;
        b[1]++;
        a[3] = b[3] = 0x3f3f3f3f;
        int mina = min(a[1], a[2]);
        int minb = min(b[1], b[2]);
        if(a[0] < mina) {
            swap(a[1], a[3]);
            if(a[2] > a[3]) swap(a[2], a[3]);
        }
        else {
            swap(a[0], a[2]);
            if(a[0] > a[1]) swap(a[0], a[1]);
        }
        if(b[0] < minb) {
            swap(b[1], b[3]);
            if(b[2] > b[3]) swap(b[2], b[3]);
        }
        else {
            swap(b[0], b[2]);
            if(b[0] > b[1]) swap(b[0], b[1]);
        }
        int ans = 0;
        for(int i = 0; i < 4; ++i) {
            if(a[i] > b[i]) {
                ans = -1;
                break;
            }
            else if(a[i] < b[i]) {
                ans = 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
