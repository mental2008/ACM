#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, a, b, k;
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    while(k--) {
        int ta, fa, tb, fb;
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        if(ta == tb) {
            printf("%d\n", abs(fb - fa));
        }
        else {
            if(fa <= b && fa >= a) {
                printf("%d\n", abs(tb - ta) + abs(fb - fa));
            }
            else if(fa > b) {
                printf("%d\n", abs(tb - ta) + abs(fa - b) + abs(b - fb));
            }
            else {
                printf("%d\n", abs(tb - ta) + abs(fa - a) + abs(a - fb));
            }
        }
    }
    return 0;
}
