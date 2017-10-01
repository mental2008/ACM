#include <bits/stdc++.h>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
int main() {
    int R;
    while(~scanf("%d", &R)) {
        int score = 0;
        for(int i = 0; i < 3; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(x == 0 && y == 0) {
                score += 10;
                continue;
            }
            for(int j = 1; j <= 10; ++j) {
                if((x * x + y * y <= (j * R) * (j * R)) && (x * x + y * y > (j - 1) * R * (j - 1) * R)) {
                    score += (11 - j);
                    break;
                }
            }
        }
        printf("%d\n", score);
    }
    return 0;
}
