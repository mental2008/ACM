#include <bits/stdc++.h>
using namespace std;
int diff;
int a, b;
int main() {
    while(~scanf("%d%d%d", &diff, &a, &b)) {
        int x;
        for(int i = 0; i <= 5000; ++i) {
            int temp = (i + 4) * (i - 3) / 2 + (i - diff + 3) * (i - diff - 2) / 2;
            if(temp == a + b) {
                x = i;
                break;
            }
        }
        int ans = a - (x + 4) * (x - 3) / 2;
        printf("%d\n", ans);
    }
    return 0;
}
