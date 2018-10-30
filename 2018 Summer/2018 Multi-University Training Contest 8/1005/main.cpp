#include <bits/stdc++.h>
using namespace std;
char s[3][3];

void f(int x, int y) {
    char temp = s[x][y];
    s[x][y] = s[x + 1][y];
    s[x + 1][y] = s[x + 1][y + 1];
    s[x + 1][y + 1] = s[x][y + 1];
    s[x][y + 1] = temp;
    return;
}

int main()
{
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int q;
        scanf("%d", &q);

        for(int i = 0; i < 3; ++i) scanf("%s", s[i]);
        while(q--) {
            char order[5];
            scanf("%s", order);
            int x, y;
            if(order[0] == '1') {
                x = 0;
                y = 0;
            }
            else if(order[0] == '2') {
                x = 0;
                y = 1;
            }
            else if(order[0] == '3') {
                x = 1;
                y = 0;
            }
            else if(order[0] == '4') {
                x = 1;
                y = 1;
            }
            if(order[1] == 'C') {
                f(x, y);
            }
            else {
                f(x, y);
                f(x, y);
                f(x, y);
            }
        }
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                printf("%c", s[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
